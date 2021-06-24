#include <iostream>
#include <list>

using namespace std;

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

	list<int> ilist;
	// ilist<int> ilist(ia, ia+11);

	for (int i = 0; i < 11; ++i)
		ilist.push_back(ia[i]);

	list<int>::iterator iter;

	cout << "{ ";
	for (iter = ilist.begin(); iter != ilist.end(); ++iter) {
		if (++iter != ilist.end())
			cout << *--iter << ", ";
		else
			cout << *--iter;
	}
	cout << " }\n";

	for (iter = ilist.begin(); iter != ilist.end(); ++iter)
		if (*iter % 2 != 0)
			ilist.erase(iter--);

	cout << "{ ";
	for (iter = ilist.begin(); iter != ilist.end(); ++iter) {
		if (++iter != ilist.end())
			cout << *--iter << ", ";
		else
			cout << *--iter;
	}
	cout << " }\n";


	return 0;
}
