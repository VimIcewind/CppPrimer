#include <iostream>
#include <vector>

using namespace std;

template <class elemType>
elemType min1(const vector<elemType> &vec)
{
	elemType min_val;

	if (vec.size() >= 1)
		min_val = vec[0];
	else
		throw "Empty vector - index";

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] < min_val)
			min_val = vec[i];
	}

	return min_val;
}

template <class elemType>
elemType min2(const vector<elemType> &vec)
{
	elemType min_val;
	typename vector<elemType>::const_iterator iter = vec.begin();

	if (iter < vec.end())
		min_val = *iter;
	else
		throw "Empty vector - index";

	for (++iter; iter < vec.end(); iter++) {
		if (*iter < min_val)
			min_val = *iter;
	}

	return min_val;
}

int main(int argc, char *argv[])
{
	int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	vector<int> iv(array, array+10);

	cout << min1(iv) << endl;
	cout << min2(iv) << endl;

	return 0;
}
