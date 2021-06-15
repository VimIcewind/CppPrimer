#ifndef ILIST_H
#define ILIST_H

#include <iostream>

using namespace std;

class ilist_item {
public:
	ilist_item(int value, ilist_item *item_to_link_to = 0);

	int value()
	{
		return _value;
	}

	ilist_item* next()
	{
		return _next;
	}

	void next(ilist_item *link)
	{
		_next = link;
	}

	void value(int new_value)
	{
		_value = new_value;
	}

private:
	int _value;
	ilist_item *_next;
};

inline ilist_item::ilist_item(int value, ilist_item *item) : _value(value)
{
	if (!item)
		_next = 0;
	else {
		_next = item->_next;
		// TODO 检查下面一条语句是否正确
		item->_next = this;
	}
}

class ilist {
public:
	ilist() : _at_front(0), _at_end(0), _size(0) {}

	ilist(const ilist&);

	ilist& operator=(const ilist&);

	int size();

	void insert_front(int value);
	void insert_end(int value);
	void insert(ilist_item *ptr, int value);
	void insert_all(const ilist&);

	void display(ostream &os = cout);

	ilist_item* find(int value, ilist_item *start_at = 0);

	void remove_front();
	void remove_all();

	int remove(int value);

	void concat(const ilist&);

	void reverse();

	ilist_item* init_iter(ilist_item *it = 0);
	ilist_item* next_iter();

private:
	void bump_up_size();
	void bump_down_size();

	ilist_item *_at_front;
	ilist_item *_at_end;
	ilist_item *_current;

	int _size;
};

inline void ilist::insert_all(const ilist &rhs)
{
	ilist_item *pt = rhs._at_front;

	while (pt) {
		insert_end(pt->value());
		pt = pt->next();
	}
}

inline ilist::ilist(const ilist &rhs) : _at_front(0), _at_end(0)
{
	insert_all(rhs);
}

inline ilist& ilist::operator=(const ilist &rhs)
{
	if (this != &rhs) {
		remove_all();
		insert_all(rhs);
	}
	return *this;
}

inline int ilist::size()
{
	return _size;
}

inline void ilist::bump_up_size()
{
	++_size;
}

inline void ilist::bump_down_size()
{
	--_size;
}

inline void ilist::insert_front(int value)
{
	ilist_item *ptr = new ilist_item(value);
	if (!_at_front)
		_at_front = _at_end = ptr;
	else {
		ptr->next(_at_front);
		_at_front = ptr;
	}
	bump_up_size();
}

inline void ilist::insert_end(int value)
{
	if (!_at_end)
		_at_end = _at_front = new ilist_item(value);
	else
		_at_end = new ilist_item(value, _at_end);
	bump_up_size();
}

inline void ilist::insert(ilist_item *ptr, int value)
{
	if (!ptr)
		insert_front(value);
	else {
		bump_up_size();
		new ilist_item(value, ptr);
	}
}

ilist_item* ilist::find(int value, ilist_item *start_at)
{
	ilist_item *ptr = start_at ? start_at : _at_front;

	while (ptr) {
		if (ptr->value() == value)
			break;
		ptr = ptr->next();
	}

	return ptr;
}

void ilist::display(ostream &os)
{
	os << "\n( " << _size << " ) ( ";
	ilist_item *ptr = _at_front;

	while (ptr) {
		os << ptr->value() << " ";
		ptr = ptr->next();
	}

	os << ")\n";
}

inline void ilist::remove_front()
{
	if (_at_front) {
		ilist_item *ptr = _at_front;
		_at_front = _at_front->next();

		if (_current == ptr)
			_current = _at_front;

		bump_down_size();
		delete ptr;
	}
}

inline void ilist::remove_all()
{
	while (_at_front)
		remove_front();

	_size = 0;
	_at_front = _at_end = 0;
}

int ilist::remove(int value)
{
	ilist_item *plist = _at_front;
	int elem_cnt = 0;

	while (plist && plist->value() == value) {
		plist = plist->next();
		remove_front();
		++elem_cnt;
	}

	if (!plist)
		return elem_cnt;
	ilist_item *prev = plist;
	plist = plist->next();

	while (plist) {
		if (plist->value() == value) {
			prev->next(plist->next());

			if (_current == plist)
				_current = prev->next();

			delete plist;
			++elem_cnt;
			bump_down_size();
			plist = prev->next();
			if (!plist) {
				_at_end = prev;
				return elem_cnt;
			}
		} else {
			prev = plist;
			plist = plist->next();
		}
	}
	return elem_cnt;
}

void ilist::concat(const ilist &il)
{
	ilist_item *ptr = il._at_front;

	while (ptr) {
		insert_end(ptr->value());
		ptr = ptr->next();
	}
}

void ilist::reverse()
{
	ilist_item *ptr = _at_front;
	ilist_item *prev = 0;

	_at_front = _at_end;
	_at_end = ptr;

	while (ptr != _at_front) {
		ilist_item *tmp = ptr->next();
		ptr->next(prev);
		prev = ptr;
		ptr = tmp;
	}
	_at_front->next(prev);
}

inline ilist_item* ilist::init_iter(ilist_item *it)
{
	return _current = it ? it : _at_front;
}

inline ilist_item* ilist::next_iter()
{
	ilist_item *next = _current ? _current = _current->next() : _current;

	return next;
}

#endif /* end of include guard: ILIST_H */
