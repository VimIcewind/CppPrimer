#include <iostream>

using namespace std;

int main()
{
	string word, lastword;

	while (cin >> word) {
		if (word == lastword)
			break;
		lastword = word;
	}

	if (word != "" && word == lastword)
		cout << word << " occurred in succession.\n";
	else
		cout << "No word was repeated.\n";

	return 0;
}

