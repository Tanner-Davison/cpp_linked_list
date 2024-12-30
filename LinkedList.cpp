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
      cout << "[ " << temp->value << "]-> ";
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
void LinkedList::prepend(int value) {
  Node *newNode = new Node(value);
  if (length == 0) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
  length++;
  this->printList();
  cout << " ( prepend )\n";
}
void LinkedList::deleteFirst() {

  if (this->length == 0)
    return;
  Node *temp = head;
  if (length == 1) {
    head = nullptr;
    tail = nullptr;

  } else {
    head = head->next;
  }
  delete temp;
  length--;
  this->printList();
  cout << "( delete first )\n";
}
Node *LinkedList::get(int index) {
  if (index < 0 || index > this->length) {
    cout << "incorrect value" << endl;
    return nullptr;
  }
  Node *temp = head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  cout << "Get Returned: " << temp->value << endl;
  return temp;
}
bool LinkedList::set(int index, int value) {
  Node *temp = get(index);
  if (temp) {
    temp->value = value;
    return true;
  }
  return false;
}
bool LinkedList::insert(int index, int value) {
  if (index < 0 || index > this->length)
    return false;
  if (index == 0) {
    prepend(value);
    return true;
  }
  Node *newNode = new Node(value);
  Node *temp = get(index - 1);
  newNode->next = temp->next;
  temp->next = newNode;
  length++;
  return true;
}
void LinkedList::deleteNode(int index) {
  if (index == 0)
    return deleteFirst();
  if (index == length - 1)
    return deleteLast();
  Node *prev = get(index - 1);
  Node *temp = prev->next;
  prev->next = temp->next;
  delete temp;
  length--;
}
void LinkedList::reverse() {
  if (length <= 0) {
    return;
  }
  Node *temp = this->head;
  this->head = this->tail;
  this->tail = temp;
  Node *after = temp->next;
  Node *before = nullptr;
  for (int i = 0; i < length; i++) {
    after = temp->next;
    temp->next = before;
    before = temp;
    temp = after;
  }
}
