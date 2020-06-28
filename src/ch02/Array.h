#ifndef Array_H
#define Array_H

template <class elemType>
class Array {
public:
	explicit Array(int size = DefaultArraySize);
	Array(elemType *array, int array_size);

	Array(const Array &rhs);

	virtual ~Array() {
		delete []ia;
	}

	bool operator==(const Array&) const;
	bool operator!=(const Array&) const;

	Array& operator=(const Array&);

	int size() const {
		return _size;
	}

	virtual elemType& operator[](int index) {
		return ia[index];
	}

	virtual void sort();
	virtual elemType min() const;
	virtual elemType max() const;

	virtual int find(const elemType &value) const;
protected:
	static const int DefaultArraySize = 12;
	int _size;
	elemType *ia;
};

template<class elemType>
Array<elemType>::Array(int sz)
{
	_size = sz;
	ia = new elemType[_size];
}

template<class elemType>
Array<elemType>::Array(elemType *array, int sz)
{
	_size = sz;
	ia = new elemType[_size];

	for (int ix = 0; ix < _size; ++ix)
		ia[ix] = array[ix];
}

template<class elemType>
Array<elemType>::Array(const Array &rhs)
{
	_size = rhs._size;
	ia = new elemType[_size];

	for (int ix = 0; ix < _size; ix++)
		ia[ix] = rhs.ia[ix];
}

template<class elemType>
void Array<elemType>::sort()
{

}

template<class elemType>
elemType Array<elemType>::min() const
{
	return 0;
}

template<class elemType>
elemType Array<elemType>::max() const
{
	return 0;
}

template<class elemType>
int Array<elemType>::find(const elemType &value) const
{
	return 0;
}

#endif
