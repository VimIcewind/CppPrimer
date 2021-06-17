#include <iostream>
#include <vector>

using namespace std;

int min(const vector<int> &ivec, int &occurs)
{
	int size = ivec.size();

	// 处理空 vector 异常
	// occurs 被设置为 0 表示空 vector
	if (!size) {
		occurs = 0;
		return 0;
	}

	// ok: vector 至少含有一个元素
	int minVal = ivec[0];
	occurs = 1;
	for (int ix = 1; ix < size; ++ix) {
		if (minVal == ivec[ix])
			++occurs;
		else
			if (minVal > ivec[ix]) {
				minVal = ivec[ix];
				occurs = 1;
			}
	}

	return minVal;
}

int main()
{
	int occur_cnt = 0;
	vector<int> ivec;

	for (int ix = 0; ix < 10; ++ix) {
		ivec.insert(ivec.begin(), ix);
		ivec.push_back(ix);
	}

	cout << "The min value of ( ";
	for (vector<int>::iterator iter = ivec.begin(); iter < ivec.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << ") is ";

	int minval = min(ivec, occur_cnt);

	cout << minval << ", and it occurs " << occur_cnt << (occur_cnt > 1 ? " times." : " time.") << endl;

	return 0;
}
