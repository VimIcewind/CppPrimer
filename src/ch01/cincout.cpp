#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;

	while (cin >> word)
		cout << "word read is " << word << '\n';
	cout << "ok: nomore words to read: bye!\n";

	return 0;
}
