CFLAGS=-g -Og
CC=g++

OBJECT = char_overflow bool2num ptrtest inc complex complexinc minmax sizeof bit \
	 bit_typedef bit_template initfib

all : $(OBJECT)

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
