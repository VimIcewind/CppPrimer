#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
#ifdef DEBUG
	cout << "Beginning execution of main()\n";
#endif
	string word;
	vector<string> text;
	while (cin >> word) {
#ifdef DEBUG
		cout << "word read: " << word << "\n";
#endif
		text.push_back(word);
	}

	return 0;
}
