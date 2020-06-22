CFLAGS=-g -Og
CC=g++

OBJECT = array newdelete IntArray IntArrayRC

all : $(OBJECT)

IntArray : IntArray.h IntArray.cpp
	$(CC) $(CFLAGS) -o IntArray IntArray.cpp

IntArrayRC : IntArrayRC.h IntArrayRC.cpp
	$(CC) $(CFLAGS) -o IntArrayRC IntArrayRC.cpp

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
