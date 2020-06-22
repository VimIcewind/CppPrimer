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
