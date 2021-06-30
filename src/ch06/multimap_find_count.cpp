#include <iostream>
#include <string>
#include <map>

using namespace std;

void code_fragment()
{
	multimap<string, string> authors;
	typedef multimap<string, string>::value_type valType;

	string search_item("Alain de Booton");

	authors.insert(valType(string("Barth, John"), string("Sot-Weed Factor")));
	authors.insert(valType(string("Barth, John"), string("Lost in the Funhouse")));
	authors.insert(valType(string("Alain de Booton"), string("Alanin Book")));
	authors.insert(valType(string("Alain de Booton"), string("Booton Book")));

	int number = authors.count(search_item);
	multimap<string, string>::iterator iter;
	iter = authors.find(search_item);
	for (int cnt = 0; cnt < number; ++cnt, ++iter)
		cout << (*iter).first << ' ' << (*iter).second << endl;
}

int main()
{
	code_fragment();

	return 0;
}
