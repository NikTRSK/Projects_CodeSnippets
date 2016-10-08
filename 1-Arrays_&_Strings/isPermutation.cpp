#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPermutaionBySorting(string str1, string str2) {
  if (str1.length() != str2.length())
    return false;

  // Sort the two strings
  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());

  if (str1 == str2) return true;
  else return false;
}

bool isPermutaionByCountingChars(string str1, string str2) {
  if (str1.length() != str2.length())
  return false;
  
  // define an array to store the strings
  int chars[128] = {0};

  // counts the characters in str1
  for (int i = 0; i < str1.length(); ++i) {
    int charValue = (int)(str1.at(i));
    chars[charValue]++;
  }
  // count the characters in str2 by decrementing. If we get -1 they are not equal
  for (int i = 0; i < str2.length(); ++i) {
    int charValue = (int)(str2.at(i));
    chars[charValue]--;
    if (chars[charValue] < 0) return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Wrong input!\n";
    return 1;
  }

  string str1 = argv[1];
  string str2 = argv[2];

  bool check = isPermutaionByCountingChars(str1, str2);
  cout << "Using Counting: " << std::boolalpha << check << endl;
  check = isPermutaionBySorting(str1, str2);
  cout << "Using Sorting: " << std::boolalpha << check << endl;

  return 0;
}