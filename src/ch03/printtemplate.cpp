#include <iostream>

using namespace std;

template <class elemType>
void print(elemType *pbegin, elemType *pend)
{
	while (pbegin != pend) {
		cout << *pbegin << ' ';
		++pbegin;
	}
	cout << endl;
}

int main(void)
{
	int ia[9] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
	double da[4] = {3.14, 6.28, 12.56, 25.12};
	string sa[3] = {"piglet", "eeyore", "pooh"};

	print(ia, ia+9);
	print(da, da+4);
	print(sa, sa+3);

	return 0;
}
