CFLAGS=-g -Og
CC=g++

OBJECT = main swap pswap rswap look_up ptrswap arrarg arrargref

all : $(OBJECT)

main : main.cpp
	$(CC) $(CFLAGS) -o $@ $<

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
