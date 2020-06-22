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

#endif
