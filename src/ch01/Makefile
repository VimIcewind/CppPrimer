CFLAGS=-g -Og
CC=g++

OBJECT = bookstore bookstore_if loop main cplusplus fstream

all : $(OBJECT)

main : main.cpp
	$(CC) $(CFLAGS) -DDEBUG -o main main.cpp

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o

