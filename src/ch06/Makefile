CFLAGS=-g -Og
CC=g++

OBJECT = size_capacity reserve TextQuery

all : $(OBJECT)

TextQuery : TextQuery.cpp
	$(CC) $(CFLAGS) -o $@ $<

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
