#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *next;

  Node(int valueP) {
    this->value = valueP;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head = nullptr;
  Node *tail = nullptr;
  int length;

public:
  LinkedList(int valueP) {
    Node *newNode = new Node(valueP);
    head = newNode;
    tail = newNode;
    length = 1;
  };
  ~LinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }
  void printList() {
    Node *temp = head;
    while (temp) {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }
  void append(int value) {
    Node *newNode = new Node(value);
    if (this->length == 0) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }
    ++length;
  }
  void getHead() { cout << "Head " << head->value << endl; }
  void getTail() {
    if (!this->tail) {
      cout << " Tail is nullptr! " << endl;
    } else {
      cout << "Tail: " << tail->value << endl;
    }
  }
  void getLength() {
    if (length == 0) {
      cout << "this linked list has no length" << endl;
    }
    cout << "Length: " << this->length << " --> ";
  }
  void deleteLast() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      Node *temp = head;
      Node *pre = head;
      while (temp->next) {
        pre = temp;
        temp = temp->next;
      }
      tail = pre;
      tail->next = nullptr;
    }
    delete temp;
    length--;
  }
};

int main() {
  LinkedList *myLinkedList = new LinkedList(1);
  myLinkedList->append(2);
  myLinkedList->append(3);
  myLinkedList->append(4);
  myLinkedList->deleteLast();
  myLinkedList->getLength();
  myLinkedList->getTail();
  return 0;
}

/* This version is more clear about what's actually happening:
 currentNode->next = newNode;     // Link the new node to the end
 currentNode = newNode;           // Move our position to this new last node
 Versus the less intuitive:
 tail->next = newNode;    // Same operation but less clear naming
 tail = newNode;          // Same operation but less clear naming *//* This version is more clear about what's actually happening:
   currentNode->next = newNode;     // Link the new node to the end
   currentNode = newNode;           // Move our position to this new last node
   Versus the less intuitive:
   tail->next = newNode;    // Same operation but less clear naming
   tail = newNode;          // Same operation but less clear naming */
