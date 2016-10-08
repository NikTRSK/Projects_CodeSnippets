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
}

int main(int argc, char *argv[]) {
  char str[] = "ABCD";
  int n = strlen(str);
  char substring[] = "BAC";
  bool check = permute(str, 0, n-1, substring);
  cout << std::boolalpha << check << endl;
} //