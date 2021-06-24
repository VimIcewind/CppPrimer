#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ia[] = {1, 5, 34};
	int ia2[] = {1, 2, 3};
	int ia3[] = {6, 13, 21, 29, 38, 55, 67, 89};
	vector<int> ivec;

	// 0
	ivec.push_back(0);
	// 0 1
	ivec.insert(ivec.end(), ia, ia+1);
	// 0 1 1 2 3
	ivec.insert(ivec.end(), ia2, ia2+3);
	// 0 1 1 2 3 5
	ivec.insert(ivec.end(), ia+1, ia+2);
	// 0 1 1 2 3 5 8
	ivec.push_back(8);
	// 0 1 1 2 3 5 8 13 21
	ivec.insert(ivec.end(), ia3+1, ia3+3);
	// 0 1 1 2 3 5 8 13 21 55
	ivec.insert(ivec.end(), ia3+5, ia3+6);
	// 0 1 1 2 3 5 8 13 21 55 89
	ivec.insert(ivec.end(), ia3+7, ia3+8);

	int size = ivec.size();

	cout << "{";
	for (int i = 0; i < size; ++i) {
		cout << ivec[i];
		if (i < size -1)
			cout << ", ";
	}
	cout << " }";

	return 0;
}

