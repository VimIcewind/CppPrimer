#include <iostream>

using namespace std;

int main()
{
	int i = 1;
	int *pi = &i;
	int &ri = i;
	int j = i;

	cout << i << endl;
	cout << *pi << endl;
	cout << ri << endl;
	cout << j << endl;

	cout << &i << endl;
	cout << pi << endl;
	cout << &ri << endl;
	cout << &j << endl;

	return 0;
}

