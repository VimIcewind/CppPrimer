#include <iostream>

using namespace std;

int main(void)
{
	int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *iter = &ia[0];
	int *iter_end = &ia[10];

	while (iter != iter_end) {
		cout << *iter << " " ;
		++iter;
	}

	return 0;
}
