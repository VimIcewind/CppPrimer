CFLAGS=-g -Og
CC=g++

OBJECT = pow2 pointeriter foobar stringlength strlen string carr cppstring

all : $(OBJECT)

pow2 : pow2.cpp pow.cpp
	$(CC) $(CFLAGS) -o pow2 pow2.cpp pow.cpp

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
