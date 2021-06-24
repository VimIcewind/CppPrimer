#include <iostream>

using namespace std;

int main()
{
	string name("AnnaBelle");
	int pos = name.find("Anna");

	if (pos == string::npos)
		cout << "Anna not found!\n";
	else
		cout << "Anna found at pos: " << pos << endl;

	return 0;
}
