#ifndef ILIST_H
#define ILIST_H

class ilist_item;

class ilist {
public:
	ilist() : _at_front(0), _at_end(0), _size(0) {}

	int size();

private:
	ilist(const ilist&);
	ilist& operator=(const ilist&);

	ilist_item *_at_front;
	ilist_item *_at_end;

	int _size;
};

inline int ilist::size()
{
	return _size;
}

#endif /* end of include guard: ILIST_H */
