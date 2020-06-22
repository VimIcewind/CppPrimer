#include <iostream>
#include <cassert>
#include "IntArray.h"
using namespace std;

int main(int argc, char *argv[])
{
	int ix[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	IntArray ia = IntArray(ix, 10);
	IntArray iac = ia;

	for (int i = 0; i < ia.size(); i++)
		cout << ia[i] << ' ';
	cout << endl;
	for (int i = 0; i < iac.size(); i++)
		cout << iac[i] << ' ';
	cout << endl;
	return 0;
}
