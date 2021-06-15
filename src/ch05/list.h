#ifndef LIST_H
#define LIST_H

using namespace std;

namespace Primer_Third_Edition {

template<class elemType>
class list_item {
public:
	list_item(elemType value, list_item *item = 0) : _value(value) {
		if (!item)
			_next = 0;
		else {
			_next = item->_next;
			item->_next = this;
		}
	}

	elemType value() {
		return _value;
	}

	list_item* next() {
		return _next;
	}

	void next(list_item *link) {
		_next = link;
	}

	void value(elemType new_value) {
		_value = new_value;
	}

private:
	elemType _value;
	list_item *_next;
};

template<class elemType>
class list {
public:
	list() : _at_front(0), _at_end(0), _current(0), _size(0) {}

	list(const list&);
	list& operator=(const list&);
	~list() {
		remove_all();
	}

	void insert(list_item<elemType> *ptr, elemType value);
	void insert_front(elemType value);
	void insert_end(elemType value);
	void insert_all(const list &rhs);
	int remove(elemType value);
	void remove_front();
	void remove_all();

	list_item<elemType> *find(elemType value);
	list_item<elemType> *next_iter();
	list_item<elemType> *init_iter(list_item<elemType> *it);

	void display(ostream &os = cout);
	void concat(const list&);
	void reverse();
	int size() {
		return _size;
	}

	private:
		void bump_up_size() {
			++_size;
	}

	void bump_down_size() {
		--_size;
	}

	list_item<elemType> *_at_front;
	list_item<elemType> *_at_end;
	list_item<elemType> *_current;

	int _size;
};

template<class elemType>
inline void list<elemType>::insert_all(const list &rhs)
{
	list_item<elemType> *pt = rhs._at_front;

	while (pt) {
		insert_end(pt->value());
		pt = pt->next();
	}
}

template<class elemType>
inline list<elemType>::list(const list &rhs) : _at_front(0), _at_end(0)
{
	insert_all(rhs);
}

template<class elemType>
inline list<elemType>& list<elemType>::operator=(const list &rhs)
{
	if (this != &rhs) {
		remove_all();
		insert_all(rhs);
	}
	return *this;
}

template<class elemType>
inline void list<elemType>::insert_front(elemType value)
{
	list_item<elemType> *ptr = new list_item<elemType>(value);
	if (!_at_front)
		_at_front = _at_end = ptr;
	else {
		ptr->next(_at_front);
		_at_front = ptr;
	}
	bump_up_size();
}

template<class elemType>
inline void list<elemType>::insert_end(elemType value)
{
	if (!_at_end)
		_at_end = _at_front = new list_item<elemType>(value);
	else
		_at_end = new list_item<elemType>(value, _at_end);
	bump_up_size();
}

template<class elemType>
inline void list<elemType>::insert(list_item<elemType> *ptr, elemType value)
{
	if (!ptr)
		insert_front(value);
	else {
		bump_up_size();
		new list_item<elemType>(value, ptr);
	}
}

template<class elemType>
list_item<elemType>* list<elemType>::find(elemType value)
{
	list_item<elemType> *ptr = _at_front;

	while (ptr)
	{
		if (ptr->value() == value)
			break;
		ptr = ptr->next();
	}

	return ptr;
}

template<class elemType>
void list<elemType>::display(ostream &os)
{
	os << "\n( " << _size << " ) ( ";
	list_item<elemType> *ptr = _at_front;

	while (ptr) {
		os << ptr->value() << " ";
		ptr = ptr->next();
	}

	os << ")\n";
}

template<class elemType>
inline void list<elemType>::remove_front()
{
	if (_at_front) {
		list_item<elemType> *ptr = _at_front;
		_at_front = _at_front->next();

		if (_current == ptr)
			_current = _at_front;

		bump_down_size();
		delete ptr;
	}
}

template<class elemType>
inline void list<elemType>::remove_all()
{
	while (_at_front)
		remove_front();

	_size = 0;
	_at_front = _at_end = 0;
}

template<class elemType>
int list<elemType>::remove(elemType value)
{
	list_item<elemType> *plist = _at_front;
	int elem_cnt = 0;

	while (plist && plist->value() == value) {
		plist = plist->next();
		remove_front();
		++elem_cnt;
	}

	if (!plist)
		return elem_cnt;
	list_item<elemType> *prev = plist;
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

template<class elemType>
void list<elemType>::concat(const list &il)
{
	list_item<elemType> *ptr = il._at_front;

	while (ptr) {
		insert_end(ptr->value());
		ptr = ptr->next();
	}
}

template<class elemType>
void list<elemType>::reverse()
{
	list_item<elemType> *ptr = _at_front;
	list_item<elemType> *prev = 0;

	_at_front = _at_end;
	_at_end = ptr;

	while (ptr != _at_front) {
		list_item<elemType> *tmp = ptr->next();
		ptr->next(prev);
		prev = ptr;
		ptr = tmp;
	}
	_at_front->next(prev);
}

template<class elemType>
inline list_item<elemType>* list<elemType>::init_iter(list_item<elemType> *it)
{
	return _current = it ? it : _at_front;
}

template<class elemType>
inline list_item<elemType>* list<elemType>::next_iter()
{
	list_item<elemType> *next = _current ? _current = _current->next() : _current;

	return next;
}

}

#endif //LIST_H
