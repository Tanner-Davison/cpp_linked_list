#include <iostream>
// #include <vector>

using namespace std;

class LinkedList {
private:
  int *value = new (int);
  int *next = new (int);

public:
  LinkedList(int &valueP, int &nextP) : value(&valueP), next(&nextP) {};
  ~LinkedList() {
    delete this->value;
    delete this->next;
  }
  void setValue(int &valueP) { this->value = &valueP; }
  void setNext(int &nextP) { this->next = &nextP; }
  void getValue() { cout << *this->value << endl; }
};

int main(int argc, char *argv[]) {
  int *first = new int(1);
  int *second = new int(1);

  LinkedList item1(*first, *second);
  item1.getValue();

  return 0;
}
