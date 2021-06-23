#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int ia[6] = {0, 1, 2, 3, 4, 5};
	vector<string> svec;
	list<double> dlist;

	vector<string>::iterator viter;
	list<double>::iterator liter;
	int *pia;

	pia = find(&ia[0], &ia[6], 1);
	liter = find(dlist.begin(), dlist.end(), 3.14);
	viter = find(svec.begin(), svec.end(), "algorithm");

	cout << *pia;

	return 0;
}
