#include <iostream>
#include <sstream>
using namespace std;

void URLify(char *inputstr, char *outputstr) {
  char pattern[] = "%20";
  std::istringstream  is(inputstr);
  char c;
  int i = 0;
  while(is.get(c)) {
    if(c == ' ') {
      for (int j = 0; j < strlen(pattern); ++j) {
        outputstr[i] = pattern[j];
        ++i;
      }
    }
    else {
      outputstr[i] = c;
      ++i;
    }
  }
}

int main() {
  char stri[] = "abc def gh";
  char pattern[] = "%20";
  char stro[256];
  URLify(stri, stro);
  cout << stro << endl;
}