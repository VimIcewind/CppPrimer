#include <iostream>
#include "list.h"

using namespace std;
using namespace Primer_Third_Edition;

int main()
{
	list<int> ilist;

	for (int ix = 0; ix < 10; ++ix) {
		ilist.insert_front(ix);
		ilist.insert_end(ix);
	}
	cout << "OK: after insert_front() and insert_end()\n";
	ilist.display();

	list_item<int> *it = ilist.find(8);

	cout << "\n"
		<< "Searching for the value 8: found it<<"
		<< (it ? " yes!\n" : " no!\n");
	ilist.insert(it, 1024);

	cout << "\n"
		<< "Insesrting element 1024 following the value 8\n";
	ilist.display();

	int elem_cnt = ilist.remove(8);

	cout << "\n"
		<< "Removed " << elem_cnt << " of the value 8\n";
	ilist.display();

	cout << "\n" << "Removed front element\n";

	ilist.remove_front();
	ilist.display();

	cout << "\n" << "Removed all elements\n";

	ilist.remove_all();
	ilist.display();

	return 0;
}

