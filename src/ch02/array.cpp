#include <iostream>
using namespace std;

int main()
{
	int ia[10];
	int index;

	for (index = 0; index < 10; ++index)
		ia[index] = index;
	for (index = 9; index >= 0; --index)
		cout << ia[index] << " ";
	cout << endl;

	return 0;
}
