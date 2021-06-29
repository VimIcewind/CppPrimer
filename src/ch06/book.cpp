#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	set<string> books_read;
	vector<string> books_to_read;

	books_to_read.push_back("AAA");
	books_to_read.push_back("BBBB");
	books_to_read.push_back("CCCCC");
	books_to_read.push_back("DDDDDD");
	books_to_read.push_back("EEEEEEE");
	books_to_read.push_back("FFFFFFFF");

	// initialize random number generator
	srand(33);

	int i;
	// try to pick 6 books
	for (i = 0; i < 6; ++i) {
		// generate a pseudo-random number
		int j = rand() % books_to_read.size();

		string book = books_to_read[j];
		cout << "\t" << book << endl;
		books_to_read.erase(books_to_read.begin() + j);

		if (books_read.count(book))
			cout << "\talready read \t" << book << endl;
		else {
			if (i % 4 != 0)    // notafourth book:read it
				books_read.insert(book);
			else {             // put back every fourth book
				cout << "putting back book " << book << endl;
				books_to_read.push_back(book);
			}
		}
	}
	cout << "Books read:\n";

	set<string>::iterator iter;
	for (iter = books_read.begin(); iter != books_read.end(); ++iter)
		cout << "\t" << *iter << endl;

	cout << "Books not read:\n";

	for (vector<string>::size_type i = 0; i < books_to_read.size(); ++i)
		cout << "\t" << books_to_read[i] << endl;

	return 0;
}
