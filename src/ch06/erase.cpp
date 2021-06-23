#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool do_something(list<string> ls)
{
	return false;
}

int main()
{
	list<string> slist;
	string searchValue("Quasimodo");

	list<string>::iterator iter = find(slist.begin(), slist.end(), searchValue);

	// 删除单个元素
	if (iter != slist.end())
		slist.erase(iter);

	// 删除容器中的所有元素
	slist.erase(slist.begin(), slist.end());

	// 删除由 iterator 标记的一段范围内的元素
	string val1, val2;
	list<string>::iterator first, last;
	first = find(slist.begin(), slist.end(), val1);
	last = find(slist.begin(), slist.end(), val2);
	slist.erase(first, last);

	vector<string> buffer;
	vector<string>::iterator viter = buffer.begin();

	// pop_back() 方法删除容器的末元素，它不返回元素，只是简单地删除它
	for (; viter != buffer.end(); viter++) {
		slist.push_back(*iter);
		if (!do_something(slist))
			slist.pop_back();
	}

	return 0;
}
