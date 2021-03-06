#include <iostream>
#include "ilist.h"

using namespace std;

int main()
{
	ilist mylist;

	for (int ix = 0; ix < 10; ++ix) {
		mylist.insert_front(ix);
		mylist.insert_end(ix);
	}

	cout << "OK: after insert_front() and insert_end()\n";
	mylist.display();

	ilist_item *it = mylist.find(8);

	cout << "\n"
		<< "Searching for the value 8: found it<<"
		<< (it ? " yes!\n" : " no!\n");
	int cnt = mylist.count(8);
	cout << "Found the value 8: found it " << cnt << " time" << (cnt > 1 ? "s\n" : "\n");
	mylist.insert(it, 1024);

	cout << "\n"
		<< "Inserting element 1024 following the value 8\n";
	mylist.display();
	cnt = mylist.count(1024);
	cout << "Found the value 1024: found it " << cnt << " time" << (cnt > 1 ? "s\n" : "\n");

	int elem_cnt = mylist.remove(8);

	cout << "\n"
		<< "Removed " << elem_cnt << " of the value 8\n";
	mylist.display();

	cout << "\n" << "Removed front element\n";

	mylist.remove_front();
	mylist.display();

	cout << "\n" << "Removed all elements\n";

	mylist.remove_all();
	mylist.display();

	return 0;
}
