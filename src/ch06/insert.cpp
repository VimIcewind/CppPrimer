#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> svec;
	list<string> slist;

	string spouse("Beth");

	// insert() 的第一个参数是一个位置 (指向容器中某个位置 iterator)，第二个参数是将要
	// 被插入的值，这个值被插入到由 iterator 指向的位置的前面
	slist.insert(slist.begin(), spouse);
	svec.insert(svec.begin(), spouse);

	string son("Danny");
	list<string>::iterator iter;

	// 更为随机的插入操作可以如下实现
	iter = find(slist.begin(), slist.end(), son);
	slist.insert(iter, spouse);

	string value = "test";

	// push_back() 方法给出了 "在顺序容器尾部插入单个元素" 的简短表示
	slist.push_back(value);
	// 等价于
	slist.insert(slist.end(), value);

	// insert() 方法的第二种形式支持 "在某个位置插入指定数量的元素"
	// 在 vector 的开始处插入 10 个 Anna
	string anna("Anna");
	svec.insert(svec.begin(), 10, anna);

	// insert() 方法的最后一种形式支持 "向容器插入一段范围内的元素"
	string sarray[4] = {"quasi", "simba", "frollo", "scar"};
	// 可以向字符串 vector 中插入数组中的全部或部分元素
	svec.insert(svec.begin(), sarray, sarray+4);
	svec.insert(svec.begin() + svec.size()/2, sarray+2, sarray+4);

	// 可以通过一对 iterator 来标记处待插入值的范围，可以是另一个 string 元素的 vector
	vector<string> svec_two;
	// 插入 svec 中含有的元素，从 svec_two 的中间开始
	svec_two.insert(svec_two.begin() + svec_two.size()/2,
			svec.begin(), svec.end());

	// 更一般的情况下，可以是任意一种 string 对象的容器
	string stringVal;
	// 把 svec 中含有的元素插入到 slist 中 stringVal 的前面
	list<string>::iterator liter = find(slist.begin(), slist.end(), stringVal);
	slist.insert(liter, svec.begin(), svec.end());

	return 0;
}
