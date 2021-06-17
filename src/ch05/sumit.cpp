#include <iostream>

using namespace std;

int sumit(int *parray_begin, int *parray_end)
{
	int sum = 0;

	if (!parray_begin || !parray_end)
		return sum;
	while (parray_begin != parray_end)
		sum += *parray_begin++;

	return sum;
}

int ia[6] = {0, 1, 2, 3, 4, 5};

int main()
{
	int sum = sumit(&ia[0], &ia[6]);

	cout << sum;

	return 0;
}

