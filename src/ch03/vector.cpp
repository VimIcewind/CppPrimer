#include <iostream>
#include <vector>

using namespace std;

vector<string> svec;

void simple_example()
{
	const int elem_size = 10;
	vector<int> ivec(elem_size);

	int ia[elem_size];

	for (int ix = 0; ix < elem_size; ++ ix)
		ia[ix] = ivec[ix];
	for (int ix = 0; ix < elem_size; ++ ix)
		cout << ia[ix] << ' ';
	cout << endl;
}

void print_vector(vector<int> ivec)
{
	if (ivec.empty())
		return;
	for (unsigned long ix = 0; ix < ivec.size(); ++ix)
		cout << ivec[ix] << ' ';
	cout << endl;
}

void int_and_assign()
{
	// 用另一个 vector 初始化一个 vetctor
	vector<string> user_names(svec);
	// 把一个 vector 拷贝给另一个 vector
	svec = user_names;
}
void read_write()
{
	vector <string> text;
	string word;
	while (cin >> word) {
		text.push_back(word);
	}

	cout << "words read are: \n";

	for (unsigned long ix = 0; ix < text.size(); ++ix)
		cout << text[ix] << ' ';
	cout << endl;

	cout << "words read are: \n";

	for (vector<string>::iterator it = text.begin(); it != text.end(); ++it)
		cout << *it << ' ';
	cout << endl;
}

int main(void)
{
	vector<int> ivec(10);

	simple_example();
	print_vector(ivec);
	// read_write();

	// 注意，不要混用这两种习惯用法
	vector<int> intvec;
	// intvec[0] = 1024;
	// 定义了一个空 vector，再写这样的语句：
	// cout << intvec[0];
	// Command terminated
	// 就是错误的，因为 intvec 还没有第一个元素。我们只能索引 vector 中已经存在的元素。
	// size() 操作返回 vector 包含的元素的个数
	cout << intvec.size() << endl;

	// 类似地，当我们用一个给定的大小定义一个 vector 时，例如：
	vector<int> ia(10);
	// 任何一个插入操作都将增加 vector 的大小，而不是覆盖掉某个现有的元素。这看起来好像是很显然的，
	// 但是下面的错误在初学下者中并不少见：
	const int size = 7;
	int intarr[size] = {0, 1, 1, 2, 3, 5, 8};
	vector<int> intvecter(size);

	for (int ix = 0; ix < size; ++ix)
		intvecter.push_back(intarr[ix]);
	// 程序结束时 intvector 包含 14 个元素，intarr 的元素从第八个元素开始插入
	for (unsigned long ix = 0; ix < intvecter.size(); ++ix)
		cout << intvecter[ix] << ' ';

	return 0;
}
