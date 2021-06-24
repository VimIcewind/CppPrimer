#include <iostream>
#include <string>

using namespace std;

int main()
{
	string elems("0123456789");
	string dept_code("03714p3");

	string::size_type pos = dept_code.find_first_not_of(elems);

	cout << pos << endl;

	return 0;
}
