#include <iostream>

using namespace std;

const int array_size = 7;
int ia1[] = {0, 1, 2, 3, 4, 5, 6};

int main(void)
{
	int ia2[array_size];

	for (int ix = 0; ix < array_size; ++ix)
		ia2[ix] = ia1[ix];
	cout << ia2 << endl;
	cout << &ia2[0] << endl;

	return 0;
}
