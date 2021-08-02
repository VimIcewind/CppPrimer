#include <iostream>
#include <vector>

using namespace std;

// 引用参数 'occurs' 可以含有第二个返回值
vector<int>::const_iterator look_up(
		const vector<int> &vec,
		int value, int &occurs)
{
	// res_iter 被初始化为最后一个元素的下一位置
	vector<int>::const_iterator res_iter = vec.end();
	occurs = 0;

	for (vector<int>::const_iterator iter = vec.begin();
			iter != vec.end();
			++iter) {
		if (*iter == value) {
			if (res_iter == vec.end())
				res_iter = iter;
			++occurs;
		}
	}
	return res_iter;
}

int main()
{
	int iarr[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> ivec(iarr, iarr+10);
	int cnt;

	vector<int>::const_iterator iter = look_up(ivec, 6, cnt);
	if (iter != ivec.end())
		cout << cnt;

	return 0;
}
