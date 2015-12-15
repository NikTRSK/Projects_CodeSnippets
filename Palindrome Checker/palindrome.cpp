#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <ctype.h>

using namespace std;

void menu();
bool palindrome(const char *, int);

int main(int argv, char * argc[])
{
	int opt;
	string word;
	do
	{
		menu();
		cout << endl;
		cin >> opt;

		if (opt == 1)
		{
			cin >> word;
			cout << word << " is";
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			if ( palindrome( word.c_str(), word.size() ) )
				cout << " a palindrome\n";
			else
				cout << " not a palindrome\n";
		}

		if (opt == 2)
		{
			string filename;
			cin >> filename;

			ifstream inputFile(filename.c_str());
			ofstream outputFile("palindromeList.txt");
			
			while (inputFile >> word)
			{
				if (word.size() > 1)	// only checks words longer than 1 character
				{
					std::transform(word.begin(), word.end(), word.begin(), ::tolower);
					if ( palindrome(word.c_str(), word.size()) )
						outputFile << word << endl;
				}
			}

			cout << "Palindrome list written to palindromeList.txt\n";
			inputFile.close();
			outputFile.close();
		}
		cout << endl;
	} while (opt < 3);
}

bool palindrome(const char *phrase, int len)
{
	if (len <= 1)
		return 1;
	else
		return (*phrase == phrase[len-1]) && palindrome(++phrase, len-2);
}

void menu()
{
	cout << "==================================" << endl;
	cout << "===RECURSIVE PALINDROME CHECKER===" << endl;
	cout << "==================================" << endl;
	cout << "1. Enter a word\n";
	cout << "\t Usage: 1 word_to_check\n";
	cout << "2. Filename with words\n";
	cout << "\t Usage: 2 filename.txt\n";
	cout << "3. Exit\n";
}