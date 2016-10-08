#include <iostream>
#include <string>
using namespace std;

/*
  Checks whether all characters in a string are unique
*/
bool isUnique(char *in) {
  for (int i = 0; i < strlen(in); ++i) {
    for (int j = i+1; j < strlen(in); ++j) {
      if (in[i] == in[j])
        return false;
    }
  }
  return true;
} // O(n^2) time & O(1) space complexity

bool isUnique2(char *in) {
  // Assumes 128 char map (ASCII)
  if (strlen(in) > 128) return false; // since ASCII has only 128 characters it must have duplicates

  bool charSet[128] = {false};
  for (int i = 0; i < strlen(in); ++i) {
    int charValue = (int)(in[i]);
    if (charSet[charValue]) return false;
    charSet[charValue] = true;
  }
  return true;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Wrong number of arguments!\nExiting...\n";
    return 1;
  }

  char *inputstr = argv[1];

  cout << "--- Using method 1 ---\n";
  cout << "The string " << inputstr << " is ";
  if (isUnique(inputstr))
    cout << "unique.\n";
  else
    cout << "not unique.\n";

  cout << "--- Using method 2 ---\n";
  cout << "The string " << inputstr << " is ";
  if (isUnique2(inputstr))
    cout << "unique.\n";
  else
    cout << "not unique.\n";

  return 0;
}