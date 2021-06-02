#include <iostream>

using namespace std;

int main(void)
{
	int ia[9] = {0, 1, 1, 2, 3, 5, 8, 18, 21};
	int *pbegin = ia;
	int *pend = ia + 9;

	while (pbegin != pend) {
		cout << *pbegin << ' ';
		++pbegin;
	}

	return 0;
}
