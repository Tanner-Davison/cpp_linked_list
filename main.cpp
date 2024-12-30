#include "./Headers/LinkedList.h"
using namespace std;

int main() {
  LinkedList *myLinkedList = new LinkedList(1);
  int myNums = 4;
  for (int i = 2; i < myNums; i++) {
    myLinkedList->append(i);
  }
  myLinkedList->getHead();
  myLinkedList->printList();
  myLinkedList->reverse();
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
