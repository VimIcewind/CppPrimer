#include <iostream>
#include <vector>

using namespace std;

bool is_equal(const vector<int> &v1, const vector<int> &v2)
{
	int size = v1.size() < v2.size() ? v1.size() : v2.size();
	bool result;

	for (int ix = 0; ix < size; ++ix) {
		if (v1[ix] != v2[ix]) {
			result = false;
			break;
		} else {
			result = true;
		}
	}

	return result;
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
