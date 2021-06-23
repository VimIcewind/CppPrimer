#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

using namespace std;

int get_word_count(string file_name)
{
	int cnt = 0;

	// TODO read the file and get word count

	return cnt;
}

int main()
{
	vector<string> svec;
	list<int> ilist;

	if (svec.empty() != true)
		cout << "This is an error here!" << endl;
	cout << svec.empty() << endl;

	string text_word;

	cout << "Please input some words:" << endl;
	while (cin >> text_word)
		svec.push_back(text_word);
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	int ia[4] = {0, 1, 2, 3};

	for (int ix = 0; ix < 4; ++ix)
		ilist.push_back(ia[ix]);
	for (list<int>::iterator iter = ilist.begin(); iter != ilist.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	int get_word_count(string file_name);
	const int list_size = 64;

	list<int> il(list_size);
	vector<string> sv(get_word_count(string("Chimera")));

	// 容器中的每个元素都被初始化为 "与该类型相关联的缺省值"。对于整数，将用缺省值 0 初始化所有元素。
	// 对于 string 类，每个元素都将用 string 的缺省构造函数初始化。

	// 除了用相关联的初始值来初始化每个元素外，我们可以指定一个值，并用它来初始化每个元素。
	list<int> ili(list_size, -1);
	vector<string> svc(24, "pooh");

	for (list<int>::iterator iter = ili.begin(); iter != ili.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	for (vector<string>::iterator iter = svc.begin(); iter != svc.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 我们将 svec 的长度增加了一倍。每个元素都被初始化为 "与元素底层类型相关联的值"
	svec.resize(2 * svec.size());
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 如果我们希望每个新元素初始化为某个其他值，则可以把该值指定为第二个参数
	// 将新元素初始化为 "piglet"
	svec.resize(2 * svec.size(), "piglet");
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 我们可以用一个现有的容器对象初始化一个新的容器对象。
	vector<string> svec2(svec);
	list<int> ilist2(ilist);

	for (vector<string>::iterator iter = svec2.begin(); iter != svec2.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	for (list<int>::iterator iter = ilist2.begin(); iter != ilist2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 我们能够定义的容器的类型有三个限制 (实际上，它们只适用于用户定义的类类型):
	// 元素类型必须支持等于操作符
	// 元素类型必须支持小于操作符
	// 元素类型必须支持一个缺省值 (对于类类型，即指缺省构造函数)
	// 所有预定义的数据类型，包括指针，都满足这些限制，C++ 标准库给出的所有类类型也一样

	return 0;
}

