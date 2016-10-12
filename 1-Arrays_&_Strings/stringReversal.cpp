#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string & reverseString(string & s) {
  for (int i = 0; i < s.length()/2; ++i)
    swap(s[i], s[s.length()-i-1]);
  return s;
}

void printReverseString(string s, int curr) {
  if (curr != s.length()) {
    printReverseString(s, curr+1);
    cout << s[curr];
  }
}

int main() {
  string test = "ABCD";

  // check for same address
  // cout << &test << endl;
  // cout << &reverseString(test) << endl;

  printReverseString(test, 0);

  return 0;
}