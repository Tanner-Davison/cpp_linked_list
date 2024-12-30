#pragma once

class Node {
public:
  int value;
  Node *next;

  Node(int valueP);
  Node *get(int index);
};
