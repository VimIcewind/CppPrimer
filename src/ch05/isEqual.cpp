#include <iostream>
#include <vector>

using namespace std;

bool is_equal(const vector<int> &v1, const vector<int> &v2)
{
	vector<int>::const_iterator it1 = v1.begin(), it2 = v2.begin();

	for (; it1 != v1.end() && it2 != v2.end(); ++it1, ++it2) {
		if (*it1 != *it2)
			return false;
	}

	return true;
}

int main()
{
	int ia1[4] = {0, 1, 1, 2};
	int ia2[7] = {0, 1, 1, 2, 3, 5, 8};

	vector<int> iv1(ia1, ia1 + 4);
	vector<int> iv2(ia2, ia2 + 7);

	cout << (is_equal(iv1, iv2) ? "true" : "false");

	return 0;
}
