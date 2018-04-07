#include <iostream>
#include "llistint.h"

using namespace std;

struct Item {
  int val;
  Item *prev;
  Item *next;
};

Node* mergeList(Node *& l1, Node *& l2) {
  Node* finalList = NULL;

  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;

  if (l1.val < l2.val) {
    finalList = l1;
    finalList.next = mergeList(l1.next, l2);
  }
  else {
    finalList = l2;
    finalList.next = mergeList(l2.next, l1);
  }

  l1 = NULL;
  l2 = NULL;
  return finalList;
}

int main() {
  // list 1
  LListInt list1;
  list1.insert(0, 1);
  list1.insert(1, 3);
  list1.insert(2, 4);
  list1.insert(3, 8);
  list1.insert(4, 25);
  list1.insert(5, 30);

  // list 2
  LListInt list2;
  list2.insert(0, 2);
  list2.insert(1, 3);
  list2.insert(2, 5);
  list2.insert(3, 6);
  list2.insert(4, 15);
  list2.insert(5, 25);

  Node * list3 = mergeList(list1.getNodeAt(0), list2.getNodeAt(0));

  return 0;
}