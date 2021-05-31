#ifndef IntArray_H
#define IntArray_H

class IntArray {
public:
	explicit IntArray(int sz = DefaultArraySize);

	IntArray(int *array, int array_size);

	IntArray(const IntArray &rhs);

	virtual ~IntArray() {
		delete [] ia;
	}

	bool operator==(const IntArray&) const;
	bool operator!=(const IntArray&) const;

	IntArray& operator=(const IntArray&);

	int size() const { return _size;};

	virtual int& operator[](int index);

	virtual void sort();

	virtual int min() const;
	virtual int max() const;

	virtual int find(int value) const;

protected:
	static const int DefaultArraySize = 12;
	void init(IntArray ia);
	void init(int sz, int *array);
	int _size;
	int *ia;

};

IntArray::IntArray(int sz)
{
	init(sz, 0);
}

IntArray::IntArray(int *array, int sz)
{
	init(sz, array);
}

IntArray::IntArray(const IntArray &rhs)
{
	init(rhs._size, rhs.ia);
}

int& IntArray::operator[](int index)
{
	return ia[index];
}

void IntArray::init(IntArray ia)
{
	for (int ix = 0; ix <ia.size(); ++ix)
		this->ia[ix] = ia[ix];
}

void IntArray::init(int sz, int *array)
{
	_size = sz;
	ia = new int[_size];
	for (int ix = 0; ix < _size; ++ix)
		if (!array)
			ia[ix] = 0;
		else ia[ix] = array[ix];
}

void IntArray::sort()
{

}

int IntArray::min() const
{
	return 0;
}

int IntArray::max() const
{
	return 0;
}

int IntArray::find(int value) const
{
	return 0;
}

#endif
