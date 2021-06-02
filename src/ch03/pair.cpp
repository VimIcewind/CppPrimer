#include <iostream>
#include <utility>

using namespace std;

class EntrySlot {

};
extern EntrySlot* look_up(string);
typedef pair<string, EntrySlot*> SymbolEntry;

EntrySlot* look_up(string)
{
	EntrySlot *es = new EntrySlot();
	return  es;
}

int main(int argc, const char *argv[])
{
	pair<string, string> author("James", "Joyce");
	string firstBook;

	// 我们可以用成员访问符号访问 pair 中的单个元素，他们的名字为 first 和 second
	if (author.first == "James" && author.second == "Joyce")
		firstBook = "Stephen Hero";

	// 如果我们希望定义大量相同 pair 类型的对象，那么最方便的做法就是用 typedef
	typedef pair<string, string> Authors;
	Authors proust("marcel", "proust");
	Authors joyce("james", "joyce");
	Authors musil("robert", "musil");

	// 下面是第二个 pair 。一个元素持有对象的名字，另一个元素持有指向其符号表入口得指针

	SymbolEntry current_entry("author", look_up("author"));

	if (EntrySlot *it = look_up("editor")) {
		current_entry.first = "editor";
		current_entry.second = it;
	}

	return 0;
}
