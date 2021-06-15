#include <iostream>
#include "ilist.h"

using namespace std;

int main()
{
	ilist mylist;
	int ia[] = {1, 2, 3, 5, 8, 13};

	ilist_item *p;

	p = mylist.insert_front(21);
	mylist.insert_front(1);
	mylist.insert_front(0);
	cout << "mylist: ";
	mylist.display();

	mylist.insert(0, -3);
	cout << "mylist: ";
	mylist.display();

	mylist.insert(p, -33);
	cout << "mylist: ";
	mylist.display();

	mylist.insert_end(-55);
	cout << "mylist: ";
	mylist.display();

	ilist_item *it = mylist.find(1);
	mylist.insert(it, ia, 6);

	cout << "mylist: ";
	mylist.display();

	return 0;
}
