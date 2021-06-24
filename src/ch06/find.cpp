#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name("AnnaBelle");
	string::size_type pos = name.find("Anna");

	if (pos == string::npos)
		cout << "Anna not found!\n";
	else
		cout << "Anna found at pos: " << pos << endl;

	return 0;
}
