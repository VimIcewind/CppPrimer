#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ia[10];

	for (int ix = 0; ix < 10; ++ix)
		ia[ix] = ix;

	vector<int> ivec(ia, ia+10);
	vector<int>::iterator iter = ivec.begin();

	for (; iter != ivec.end(); ++iter) {
		cout << *iter << "\t";
		*iter *= 2;
		cout << *iter << endl;
	}

	return 0;
}
