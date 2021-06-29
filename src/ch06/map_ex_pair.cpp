#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	typedef pair<string, string> child;
	typedef vector<child> children;
	typedef string surname;
	map<surname, children> family;

	// 植入 map 中
	family["a"].push_back(make_pair(string("a1"), string("01/01")));
	family["b"].push_back(make_pair(string("b1"), string("02/02")));
	family["b"].push_back(make_pair(string("b2"), string("02/03")));
	family["c"].push_back(make_pair(string("c1"), string("03/04")));
	family["c"].push_back(make_pair(string("c2"), string("03/05")));
	family["c"].push_back(make_pair(string("c3"), string("03/06")));
	family["d"].push_back(make_pair(string("d1"), string("04/07")));
	family["d"].push_back(make_pair(string("d2"), string("04/08")));
	family["d"].push_back(make_pair(string("d3"), string("04/09")));
	family["d"].push_back(make_pair(string("d4"), string("04/10")));
	family["e"].push_back(make_pair(string("e1"), string("05/11")));
	family["e"].push_back(make_pair(string("e2"), string("05/12")));
	family["e"].push_back(make_pair(string("e3"), string("05/13")));
	family["f"].push_back(make_pair(string("f1"), string("06/14")));
	family["f"].push_back(make_pair(string("f2"), string("06/15")));
	family["g"].push_back(make_pair(string("g1"), string("07/16")));

	map<surname, children>::iterator mi;
	children::iterator vi;
	string s;

	// 显示 map 的所有项目
	for (mi = family.begin(); mi != family.end(); ++mi) {
		s = mi->first;
		cout << s << endl;
		for (vi = mi->second.begin(); vi != mi->second.end(); ++vi)
			cout << s << "\t" << vi->first << "\t" << vi->second << endl;
	}

	// 允许以姓氏来进行查询
	cout << "please enter family name: ";
	string name;
	cin >> name;

	while (!name.empty()) {
		cout << name << endl;
		for (vi = family[name].begin(); vi != family[name].end(); ++vi)
			cout << name << "\t" << vi->first << "\t" << vi->second << endl;
		cout << "please enter family name: ";
		cin >> name;
	}

	return 0;
}
