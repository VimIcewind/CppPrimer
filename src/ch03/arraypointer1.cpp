#include <iostream>

using namespace std;

void ia_print(int *pbegin, int *pend)
{
	while (pbegin != pend) {
		cout << *pbegin << ' ';
		++pbegin;
	}
}

int main()
{
	int ia[9] = {0, 1, 1, 2, 3, 5, 8, 18, 21};
	ia_print(ia, ia + 9);

	return 0;
}
