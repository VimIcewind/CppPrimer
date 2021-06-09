#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

int main()
{
	size_t ia;
	ia = sizeof(ia);
	ia = sizeof ia;

	// ia = sizeof int; // error: expected primary-expression before 'int'
	ia = sizeof(int);   // ok
	int *pi = new int[12];
	cout << "pi: " << sizeof(pi)
		<< " *pi: " << sizeof(*pi)
		<< endl;

	// 一个 string 的大小与它所指的字符串的长度无关
	string st1("foobar");
	string st2("a might oak");
	string *ps = &st1;
	cout << "st1: " << sizeof(st1)
		<< " st2: " << sizeof(st2)
		<< " ps: " << sizeof(ps)
		<< " *ps: " << sizeof(*ps)
		<< endl;
	cout << "short :\t" << sizeof(short) << endl;
	cout << "short* :\t" << sizeof(short*) << endl;
	cout << "short& :\t" << sizeof(short&) << endl;
	cout << "short[3] :\t" << sizeof(short[3]) << endl;
	// 正如上面的例子所显示的那样，应用在指针类型上的 sizeof 操作符返回的是包含该类型地址所需的内存长度
	// 但是，应用在引用类型上的 sizeof 操作符返回的是包含被引用对象所需的内存长度

	// sizeof 操作符应用在 char 类型上时，在所有的 C++ 实现中结果都是1
	size_t char_size = sizeof(char);
	cout << "char size is " << char_size << endl;
	// char size is 1

	// sizeof 操作符在编译时刻计算，因此被看作是常量表达式。它可以用于任何需要常量表达式的地方
	int array[sizeof(int)];
	cout << "int size is " << sizeof(int) << endl;
	cout << "int array[sizeof(int)] size is " << sizeof(array) << endl;

	return 0;
}
