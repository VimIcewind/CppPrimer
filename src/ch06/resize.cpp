#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> svec;
	svec.reserve(1024);
	string text_word;

	while (cin >> text_word)
		svec.push_back(text_word);
	svec.resize(svec.size() + svec.size()/2);

	return 0;
}

