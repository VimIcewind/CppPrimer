#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str("/.+(STL).*$1/");
	string t("/.+(STL).*$1/");

	string::size_type begin = str.find_first_of('/');

	str.erase(begin, 4);

	string::size_type right = str.find_first_of(')');

	str.erase(right, 6);

	string::size_type tleft = t.find_first_of('S');
	string::iterator l1 = t.begin();
	string::iterator l2 = t.begin() + tleft;

	t.erase(l1, l2);

	string::size_type tright = t.find_first_of(')');
	string::iterator r1 = t.begin() + tright;
	string::iterator r2 = t.end();
	t.erase(r1, r2);
	
	cout << str << endl;
	cout << t << endl;

	return 0;
}
