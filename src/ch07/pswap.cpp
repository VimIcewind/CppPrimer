#include <iostream>

using namespace std;

void pswap(int *, int *);

int main()
{
	int i = 10;
	int j = 20;

	cout << "Before pswap():\t: " << i << "\tj: " << j << endl;
	pswap(&i, &j);
	cout << "After pswap():\t: " << i << "\tj: " << j << endl;

	return 0;
}

// pswap() 交换v1和v2指向的值
void pswap(int *v1, int *v2)
{
	int tmp = *v2;
	*v2 = *v1;
	*v1 = tmp;
}
