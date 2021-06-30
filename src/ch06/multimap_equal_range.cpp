#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

void code_fragment()
{
	multimap<string, string> authors;
	typedef multimap<string, string>::value_type valType;

	string search_item("Haruki Murakami");

	authors.insert(valType(string("Barth, John"), string("Sot-Weed Factor")));
	authors.insert(valType(string("Barth, John"), string("Lost in the Funhouse")));
	authors.insert(valType(string("Haruki Murakami"), string("Haruki Book")));
	authors.insert(valType(string("Haruki Murakami"), string("Murakami Book")));

	while (cin && cin >> search_item)
		switch (authors.count(search_item)) {
		// 不存在，继续往下走
		case 0:
			break;
		// 只有一项，使用普通的 find() 操作
		case 1: {

			multimap<string, string>::iterator iter;
			iter = authors.find(search_item);
			cout << (*iter).first << ' ' << (*iter).second << endl;
			break;
		}
		// 出现多项 ...
		default:
			typedef multimap<string, string>::iterator iterator;
			pair<iterator, iterator> pos;

			// pos.first 指向第一个出现
			// pos.second 指向值不再出现的位置
			pos = authors.equal_range(search_item);
			for (; pos.first != pos.second; pos.first++)
				cout << (*pos.first).first << ' ' << (*pos.first).second << endl;
		}
}

int main()
{
	code_fragment();

	return 0;
}

