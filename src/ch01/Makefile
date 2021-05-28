CFLAGS=-g -Og
CC=g++

OBJECT = bookstore bookstore_if fstream

all : $(OBJECT)

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o

