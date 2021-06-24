#include <iostream>
#include <string>

using namespace std;

int main()
{
	string numerics("0123456789");
	string name("r2d2");
	string::size_type pos = name.find_first_of(numerics);

	cout << "found numeric at index: " << pos << "\telement is " << name[pos] << endl;

	return 0;
}
