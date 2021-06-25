#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentence("kind of");
	string s1("whistle");
	string s2("pixie");

	sentence.insert(0, "A ").insert(2, s1).erase(8, 1).insert(8, "ing-d").
		insert(13, s2, 1, s2.size() - 1).insert(17, " ");
	sentence.insert(sentence.size(), " walk.");

	cout << sentence << endl;

	return 0;
}
