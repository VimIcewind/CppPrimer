#include <iostream>
#include <string>

using namespace std;

int main()
{
	int errors = 0;
	string str("a very long literal string");

	for (int ix = 0; ix < 1000000; ++ix) {
		int len = str.size();
		string str2 = str;
		if (str == str2)
			++errors;
	}
	cout << "string class: "
		<< errors << " errors occurred.\n";
}
