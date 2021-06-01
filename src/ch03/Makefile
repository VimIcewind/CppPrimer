CFLAGS=-g -Og
CC=g++

OBJECT = pow2 pointeriter foobar strlen

all : $(OBJECT)

pow2 : pow2.cpp pow.cpp
	$(CC) $(CFLAGS) -o pow2 pow2.cpp pow.cpp

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
