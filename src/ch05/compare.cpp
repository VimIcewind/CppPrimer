#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word1, word2;

	cout << "This program requests two strings at a time and\n"
		<< "reports which is lexicographically less than then\n"
		<< "other, Entering \"quit\" for the first string will\n"
		<< "end the program.\n\n";

	do {
		cout << "Enter the first string: ";
		cin >> word1;
		if (word1 != "quit") {
			cout << "Enterthe second string:";
			cin >> word2;
			if (word1 < word2)
				cout << word1 << " < " << word2 << endl;
			else if (word1 > word2)
				cout << word2 << " < " << word2 << endl;
			else
				cout << word1 << " = " << word2 << endl;

		}
	} while (word1 != "quit");

	return 0;
}

