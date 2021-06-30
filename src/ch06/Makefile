CFLAGS=-g -Og
CC=g++

OBJECT = size_capacity reserve resize container iterator insert erase assign swap \
	 algorithm ivec ilist find find_first_of findall rfind find_first_not_of \
	 find_num_alph maxmin minmax erase_ex string_ex assign_append replace_ex \
	 map map_ex map_ex_pair EOF text_query book TextQuery multimap_find_count \

all : $(OBJECT)

TextQuery : TextQuery.cpp
	$(CC) $(CFLAGS) -o $@ $<

map_ex: map_ex.cpp
	$(CC) $(CFLAGS) -o $@ $<

map_ex_pair : map_ex_pair.cpp
	$(CC) $(CFLAGS) -o $@ $<

.cpp.s :
	$(CC) $(CFLAGS) -S $*.cpp
.cpp.o :
	$(CC) $(CFLAGS) -c $*.cpp

clean :
	rm -rf $(OBJECT) *.S *.s *.o
