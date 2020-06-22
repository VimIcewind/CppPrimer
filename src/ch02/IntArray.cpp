#include <iostream>
#include <cassert>
#include "IntArray.h"
using namespace std;

IntArray::IntArray(int sz)
{
	_size = sz;
	ia = new int[_size];

	for (int ix = 0; ix < _size; ++ix)
		ia[ix] = 0;
}

IntArray::IntArray(int *array, int sz)
{
	_size = sz;
	ia = new int[_size];

	for (int ix = 0; ix < _size; ++ix)
		ia[ix] = array[ix];
}

IntArray::IntArray(const IntArray &rhs)
{
	_size = rhs._size;
	ia = new int[_size];

	for (int ix = 0; ix < _size; ix++)
		ia[ix] = rhs.ia[ix];
}

int& IntArray::operator[](int index)
{
	assert(index >= 0 && index < _size);
	return ia[index];
}

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
