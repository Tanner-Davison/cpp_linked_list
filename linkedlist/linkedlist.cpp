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
      this->length = 1;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
      ++this->length;
    }
  }
  void getHead() { cout << "Head " << head->value << endl; }
  void getTail() { cout << "Tail: " << tail->value << endl; }
  void getLength() { cout << "Length: " << this->length << " --> "; }
};

int main() {
  LinkedList *myLinkedList = new LinkedList(4);
  myLinkedList->getHead();
  myLinkedList->getTail();

  myLinkedList->getLength();

  myLinkedList->append(8);
  myLinkedList->getLength();
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
