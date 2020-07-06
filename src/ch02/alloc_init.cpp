#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef string noMem;

int *allocate_array(int cnt)
{
	int *pa = new int[cnt];

	return pa ;
}

void sort_array(int * pi, int cnt)
{

}

void register_data(int *pi)
{

}

int *alloc_and_init(string file_name)
{
	try {
		ifstream infile(file_name);
		if (!infile)
			throw "cannot open file";
		int elem_cnt;
		infile >> elem_cnt;
		if (!infile || elem_cnt <= 0)
			throw "invalid elem_cnt";
		int *pi = allocate_array(elem_cnt);

		int elem;
		int index = 0;
		while (cin >> elem) {
			if (index >= elem_cnt)
				throw "too many input elements";
			pi[index++] = elem;
		}

		sort_array(pi, elem_cnt);
		register_data(pi);

		return pi;
	} catch(const noMem &n) {
		cout << "allocate_array() error " << n << endl;
		throw;
	} catch(int i) {
		cout << "sort_array() error " << i << endl;
		throw;
	} catch(const string &s) {
		cout << "register_data() error " << s << endl;
		throw;
	} catch(const char *s) {
		cout << "error: " << s << endl;
		throw;
	}
}

int main(int argc, char *argv[])
{
	cout << alloc_and_init("testfile") << endl;

	return 0;
}
