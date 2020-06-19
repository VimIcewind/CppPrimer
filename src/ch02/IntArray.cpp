#include <iostream>
#include <cassert>
using namespace std;

class IntArray {
public:
	explicit IntArray(int sz = DefaultArraySize);

	IntArray(int *array, int array_size);

	IntArray(const IntArray &rhs);

	~IntArray() {
		delete [] ia;
	}

	bool operator==(const IntArray&) const;
	bool operator!=(const IntArray&) const;

	IntArray& operator=(const IntArray&);

	int& operator[](int index);

	int size() const { return _size;};
	void sort();

	int min() const;
	int max() const;

	int find(int value) const;

private:
	int _size;
	int *ia;
	static const int DefaultArraySize = 0;

};

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
