CFLAGS=-g -Og
CC=g++

OBJECT = array newdelete IntArray IntArrayRC ArrayTest ArrayRCTest stats alloc_init \
	vectortest sort

all : $(OBJECT)

ArrayTest : Array.h ArrayTest.cpp
	$(CC) $(CFLAGS) -o ArrayTest ArrayTest.cpp

ArrayRCTest : Array.h ArrayRC.h ArrayRCTest.cpp
	$(CC) $(CFLAGS) -o ArrayRCTest ArrayRCTest.cpp

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
