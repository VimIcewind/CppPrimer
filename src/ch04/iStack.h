#ifndef ISTACK_H
#define ISTACK_H

#include <iostream>
#include <vector>

using namespace std;

class iStack {
public:
	iStack(int capacity) : _stack(capacity), _top(0) { }

	bool pop(int &value);
	bool push(int value);

	bool peek(int &value);

	bool full();
	bool empty();
	void display();

	int size();
private:
	int _top;
	vector<int> _stack;
};

inline int iStack::size()
{
	return _top;
}

inline bool iStack::empty()
{
	return _top ? false : true;
}

inline bool iStack::full()
{
	return _top < _stack.size() - 1 ? false : true;
}

bool iStack::pop(int &top_value)
{
	if (empty())
		return false;

	top_value = _stack[--_top];
	cout << "iStack::pop(): " << top_value << endl;

	return true;
}

bool iStack::push(int value)
{
	cout << "iStack::push(" << value <<")\n";

	if (full())
		return false;
	_stack[_top++] = value;
	return true;
}

bool iStack::peek(int &top_value)
{
	if (empty())
		return false;

	top_value = _stack[_top - 1];
	cout << "iStack::peek(): " << top_value << endl;

	return true;
}

void iStack::display()
{
	if (!size()) {
		cout << "( 0 )\n";
		return;
	}
	cout << "( " << size() << " ) ( bot: ";
	for (int ix = 0; ix < _top; ++ix)
		cout << _stack[ix] << " ";
	cout << ":top )\n";
}


#endif /* end of include guard: ISTACK_H */
