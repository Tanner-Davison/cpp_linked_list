#include "./Headers/LinkedList.h"
using namespace std;

int main() {
  LinkedList *myLinkedList = new LinkedList(1);

  myLinkedList->append(2);
  myLinkedList->append(3);
  myLinkedList->append(4);
  myLinkedList->deleteLast();
  myLinkedList->append(5);
  myLinkedList->prepend(30);
  myLinkedList->deleteFirst();
  cout << myLinkedList->get(3)->value << endl;
  myLinkedList->set(2, 200);
  myLinkedList->insert(1, 300);
  myLinkedList->deleteNode(3);
  myLinkedList->deleteNode(1);
  myLinkedList->deleteNode(2);
  myLinkedList->printList();

  delete myLinkedList;
  return 0;
}
/* This version is more clear about what's actually happening:
     currentNode->next = newNode;      // Link the new node to the end
     currentNode = newNode;           // Move our position to this new last node

  Versus the less intuitive:
     tail->next = newNode;             // Same operation but less clear naming
     tail = newNode;                  // Same operation but less clear naming */

/* This version is more clear about what's actually happening:
     currentNode->next = newNode;     // Link the new node to the end
     currentNode = newNode;          // Move our position to this new last node

  Versus the less intuitive:
     tail->next = newNode;        // Same operation but less clear naming
     tail = newNode;             // Same operation but less clear naming */
