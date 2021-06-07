#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int elem_cnt = 0;
	vector<int> ivec(10);
	int some_value = 16;

	vector<int>::iterator iter = ivec.begin();

	while (iter != ivec.end()) {
		elem_cnt += *iter < some_value;
		++iter;
	}
	cout << elem_cnt;

	return 0;
}
