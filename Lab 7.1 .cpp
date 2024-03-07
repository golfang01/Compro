#include <stdio.h>
#include <string.h>

struct studentNode {
  char name[20];
  int age;
  char sex;
  float gpa;
};

class LinkedList {
protected:
  struct studentNode *start, **now;

public:
  LinkedList();
  ~LinkedList();
  void InsNode(char n[], int a, char s, float g);
  void DelNode();
  void GoNext();
  virtual void ShowNode();
};

class NewList : public LinkedList {
public:
  void GoFirst();  // Change to GoNext
  virtual void ShowNode();
};

LinkedList::LinkedList() {
  start = nullptr;
  now = &start;
}

LinkedList::~LinkedList() {
  // Add code to deallocate memory for linked list nodes
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
  *now = new studentNode;
  strncpy((*now)->name, n, sizeof((*now)->name));
  (*now)->age = a;
  (*now)->sex = s;
  (*now)->gpa = g;
  (*now)->now = nullptr;
  now = &((*now)->now);
}

void LinkedList::DelNode() {
  if (*now != nullptr) {
    studentNode *temp = *now;
    *now = (*now)->now;
    delete temp;
  }
}

void LinkedList::GoNext() {
  if (*now != nullptr) {
    now = &((*now)->now);
  }
}

void LinkedList::ShowNode() {
  if (*now != nullptr) {
    printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
  }
}

void NewList::GoFirst() {
  now = &start;
}

void NewList::ShowNode() {
  studentNode *current = start;
  while (current != nullptr) {
    printf("%s %d %c %.2f\n", current->name, current->age, current->sex, current->gpa);
    current = current->now;
  }
}

int main() {
  LinkedList listA;
  NewList listB;
  LinkedList *listC;

  listA.InsNode("one", 1, 'A', 1.1);
  listA.InsNode("two", 2, 'B', 2.2);
  listA.InsNode("three", 3, 'C', 3.3);
  listA.GoNext();
  listA.ShowNode();

  listB.InsNode("four", 4, 'D', 4.4);
  listB.InsNode("five", 5, 'E', 5.5);
  listB.InsNode("six", 6, 'F', 6.6);
  listB.GoNext();
  listB.DelNode();
  listB.ShowNode();

  listC = &listA;
  listC->GoNext();
  listC->ShowNode();

  listC = &listB;
  listC->ShowNode();

  return 0;
}
