#include "./Headers/LinkedList.h"
#include "./Headers/Node.h"

LinkedList::LinkedList(int valueP) {
  Node *newNode = new Node(valueP);
  head = newNode;
  tail = newNode;
  length = 1;
};
LinkedList::~LinkedList() {
  Node *temp = head;
  while (head) {
    head = head->next;
    delete temp;
    temp = head;
  }
};

void LinkedList::printList() {
  Node *temp = head;
  cout << "\n";
  while (temp != nullptr) {
    if (temp == head) {
      cout << "[Head " << temp->value << "]->";
    } else if (temp == this->tail) {
      cout << "[" << temp->value << " Tail]";
    } else {
      cout << "[" << temp->value << "]-> ";
    }
    temp = temp->next;
  }
}
void LinkedList::append(int value) {
  Node *newNode = new Node(value);
  if (this->length == 0) {
    this->head = newNode;
    this->tail = newNode;
  } else {
    this->tail->next = newNode;
    this->tail = newNode;
  }
  ++length;
  this->printList();
  cout << " ( appended ) ";
}
void LinkedList::getHead() { cout << "Head " << head->value << endl; }
void LinkedList::getTail() {
  if (!this->tail) {
    cout << " Tail is nullptr! " << endl;
  } else {
    cout << "Tail: " << tail->value << endl;
  }
}
void LinkedList::getLength() {
  if (length == 0) {
    cout << "this linked list has no length" << endl;
  }
  cout << "Length: " << this->length << " --> ";
}
void LinkedList::deleteLast() {
  if (length == 0)
    return;
  Node *temp = head;
  if (length == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
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
  cout << "\n";
  this->printList();
  cout << " ( delete ) \n";
}
