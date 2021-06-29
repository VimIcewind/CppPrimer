#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	typedef vector<string> children;
	typedef string surname;
	map<surname, children> family;

	// 植入 map 中
	family["a"].push_back("a1");
	family["b"].push_back("b1");
	family["b"].push_back("b2");
	family["c"].push_back("c1");
	family["c"].push_back("c2");
	family["c"].push_back("c3");
	family["d"].push_back("d1");
	family["d"].push_back("d2");
	family["d"].push_back("d3");
	family["d"].push_back("d4");
	family["e"].push_back("e1");
	family["e"].push_back("e2");
	family["e"].push_back("e3");
	family["f"].push_back("f1");
	family["f"].push_back("f2");
	family["g"].push_back("g1");

	map<surname, children>::iterator mi;
	children::iterator vi;
	string s;

	// 显示 map 的所有项目
	for (mi = family.begin(); mi != family.end(); ++mi) {
		s = mi->first;
		cout << s << endl;
		for (vi = mi->second.begin(); vi != mi->second.end(); ++vi)
			cout << s << "\t" << *vi << endl;
	}

	// 允许以姓氏来进行查询
	cout << "please enter family name: ";
	string name;
	cin >> name;

	while (!name.empty()) {
		cout << name << endl;
		for (vi = family[name].begin(); vi != family[name].end(); ++vi)
			cout << name << "\t" << *vi << endl;
		cout << "please enter family name: ";
		cin >> name;
	}

	return 0;
}
