#include <vector>
#include <cassert>

using namespace std;

int main()
{
	int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> ivec(10);
	int ix_vec = 0, ix_ia = 9;

	while (ix_vec < 10)
		ivec[ix_vec++] = ia[ix_ia--];
	int *pia = &ia[9];
	vector<int>::iterator iter = ivec.begin();
	while (iter != ivec.end())
		assert(*iter++ == *pia--);

	return 0;
}
