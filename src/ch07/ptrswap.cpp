#include <iostream>

using namespace std;

void ptrswap(int *&, int *&);

int main()
{
	int i = 10;
	int j = 20;

	int *pi = &i;
	int *pj = &j;

	cout << "Before ptrswap():\tpi: " << *pi << "\tpj: " << *pj << endl;
	ptrswap(pi, pj);
	cout << "After ptrswap():\tpi: " << *pi << "\tpj: " << *pj << endl;

	return 0;
}

// ptrswap() 交换v1和v2的值
void ptrswap(int *&v1, int *&v2)
{
	int *tmp = v2;
	v2 = v1;
	v1 = tmp;
}
