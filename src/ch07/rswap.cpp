#include <iostream>

using namespace std;

void rswap(int &, int &);

int main()
{
	int i = 10;
	int j = 20;

	cout << "Before rswap():\ti: " << i << "\tj: " << j << endl;
	rswap(i, j);
	cout << "After rswap():\ti: " << i << "\tj: " << j << endl;

	return 0;
}

// rswap() 交换v1和v2指向的值
void rswap(int &v1, int &v2)
{
	int tmp = v2;
	v2 = v1;
	v1 = tmp;
}
