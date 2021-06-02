CFLAGS=-g -Og
CC=g++

OBJECT = pow2 pointeriter foobar stringlength emptystring strlen string carr cppstring \
	 const reference val_ptr_ref_assign array arrayarray arraypointer arraypointer1 \
	 printtemplate sort vector complex typedef volatile

all : $(OBJECT)

pow2 : pow2.cpp pow.cpp
	$(CC) $(CFLAGS) -o pow2 pow2.cpp pow.cpp

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
