#include <iostream>
#include "llistint.h"

using namespace std;

struct Item {
  int val;
  // Item *prev;
  Item *next;
};

Item *printReverse(Item *& head) {
  if (head == NULL) return NULL;
  if (head->next == NULL) return head;

  Item *reverse = printReverse(head->next);

  reverse->next->next = head;

  head->next = NULL;
  return reverse;
}

void reverseListIter(Item *& head) {
  Item *current = head;
  Item *prev = NULL;
  Item * next;
  while (current != NULL) {
    next = current->next;
    prev = current;
    current = next;
  }

  head = prev;
}

int main() {
  Item *i1 = new Item();
  Item *i2 = new Item();
  Item *i3 = new Item();
  i1->val = 3;
  i2->val = 5;
  i3->val = 7;

  i1->next = i2;
  i2->next = i3;
  i3->next = NULL;

  Item *temp = i1;
  while(temp != NULL) {
    cout << temp->val << endl;
    temp = temp->next;
  }

  cout << "---------\n";
  temp = printReverse(i1);
  // temp = i1;
  while(temp != NULL) {
    cout << temp->val << endl;
    temp = temp->next;
  }
  // printReverse(i1);
}