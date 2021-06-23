#include <iostream>
#include <vector>
#include <iterator>
#include <list>

using namespace std;

int main()
{
	// 迭代器 (iterator) 提供了一种一般化的方法，对顺序或关联容器类型中的每个元素进行连续访问。
	// 例如，假设 iter 为任意容器类型的一个 iterator, 则：++iter 向前移动迭代器，使其指向容器
	// 的下一个元素，而：*iter 返回 iterator 指向元素的值。
	// 每种容器类型都提供一个 begin() 和 一个 end() 成员函数
	// begin() 返回一个 iterator, 它指向容器的第一个元素
	// end() 返回一个 iterator, 它指向容器的末元素的下一个位置

	vector<string> vec;
	// iterator 是 vector 类中定义的 typedef
	vector<string>::iterator iter = vec.begin();
	vector<string>::iterator iter_end = vec.end();

	for (; iter!= iter_end; ++iter)
		cout << *iter << '\n';

	vector<string> svec;
	string intext;

	while (cin >> intext)
		svec.push_back(intext);

	// 用 svec 的全部元素初始化 svec2
	vector<string> svec2(svec.begin(), svec.end());

	// 用 svec 的前半部分初始化 svec3
	vector<string>::iterator it = svec.begin() + svec.size()/2;
	vector<string> svec3(svec.begin(), it);

	// 用特定的 istream_iterator 类型，我们可以更直接地向 svec 插入文本元素
	// 将输入流 iterator 绑定到标准输入上
	istream_iterator<string> infile(cin);

	// 标记流结束位置的输入流 iterator
	istream_iterator<string> eos;

	// 利用通过 cin 输入的值初始化 svec
	vector<string> svecin(infile, eos);


	string words[4] = {
		"stately", "plump", "buck", "mulligan"
	};

	vector<string> vwords(words, words+4);

	int ia[6] = {0, 1, 2, 3, 4, 5};
	list<int> ilist(ia, ia+6);

	return 0;
}

// 除了 iterator 类型，每个容器还定义了一个 const iterator 类型，后者对于遍历 const 容器是
// 必需的。const iterator 允许以只读方式访问容器的底层元素。
void even_odd(const vector<int> *prec, vector<int> *prec_even, vector<int> *prec_odd)
{
	// 必须声明一个 const_iterator, 才能够遍历 pvec
	vector<int>::const_iterator c_iter = prec->begin();
	vector<int>::const_iterator c_iter_end = prec->end();

	for (; c_iter != c_iter_end; ++c_iter)
		if (*c_iter % 2)
			prec_odd->push_back(*c_iter);
		else
			prec_even->push_back(*c_iter);
}
