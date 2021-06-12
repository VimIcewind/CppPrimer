CFLAGS=-g -Og
CC=g++

OBJECT = declaration ilistTest

all : $(OBJECT)

ilistTest : ilistTest.cpp ilist.h
	$(CC) $(CFLAGS) -o $@ $<

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
