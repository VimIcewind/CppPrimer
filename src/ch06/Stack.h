#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

using namespace std;

namespace Primer_Third_Edition {

template <class elemType>
class Stack {
public:
	Stack(int capacity=0);

	bool pop(elemType &value);
	bool push(elemType value);

	bool peek(elemType &value);

	bool full();
	bool empty();
	void display();

	int size();
private:
	vector<elemType> _stack;
};

template <class elemType>
inline Stack<elemType>::Stack(int capacity)
{
	if (capacity)
		_stack.reserve(capacity);
}

template <class elemType>
inline int Stack<elemType>::size()
{
	return _stack.size();
}

template <class elemType>
inline bool Stack<elemType>::empty()
{
	return _stack.empty();
}

template <class elemType>
inline bool Stack<elemType>::full()
{
	return _stack.max_size() == _stack.capacity();
}

template <class elemType>
bool Stack<elemType>::pop(elemType &top_value)
{
	if (empty())
		return false;

	top_value = _stack[size()-1];
	_stack[size()-1];
	cout << "Stack::pop(): " << top_value << endl;

	return true;
}

template <class elemType>
bool Stack<elemType>::push(elemType value)
{
	cout << "Stack::push(" << value <<")\n";

	if (full())
		return false;
	_stack.push_back(value);
	return true;
}

template <class elemType>
bool Stack<elemType>::peek(elemType &top_value)
{
	if (empty())
		return false;

	top_value = _stack[size()-1];
	cout << "Stack::peek(): " << top_value << endl;

	return true;
}

template <class elemType>
void Stack<elemType>::display()
{
	if (!size()) {
		cout << "( 0 )\n";
		return;
	}
	cout << "( " << size() << " ) ( bot: ";
	for (int ix = 0; ix < _stack.size(); ++ix)
		cout << _stack[ix] << " ";
	cout << ":top )\n";
}


}
#endif /* end of include guard: STACK_H */
