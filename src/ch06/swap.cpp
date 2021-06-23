#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<string> slist1(10);
	list<string> slist2(24);

	// slist 1 含有 10 个元素，slist 2 含有 24 个元素
	cout << slist1.size() << ' ' << slist2.size() << endl;
	slist1.swap(slist2);
	// slist 1 含有 24 个元素，slist 2 含有 10 个元素
	cout << slist1.size() << ' ' << slist2.size() << endl;

	return 0;
}

