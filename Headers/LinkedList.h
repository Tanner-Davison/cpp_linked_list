#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList {
private:
  Node *head = nullptr;
  Node *tail = nullptr;
  int length;

public:
  LinkedList(int valueP);
  ~LinkedList();
  void printList();
  void append(int value);
  void getHead();
  void getTail();
  void getLength();
  void deleteLast();
};
