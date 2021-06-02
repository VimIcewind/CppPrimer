#include <iostream>
#include <vector>

using namespace std;

// typedef 机制为我们提供了一种通用的类型定义设施，可以用来为内置的或用户定义的数据类型引入助记符。例如：
typedef double wages;
typedef vector<int> vec_int;
typedef vec_int test_scores;
typedef bool in_attendance;
typedef int *Pint;
// 这些 typedef 名字在程序中可以被用作类型标识符

// typedef 定义以关键字 typedef 开始，后面是数据类型和标识符。这里的标识符即 typedef 名字，它并没有引入
// 一种新的类型，而只是为现有类型引入了一个助记符号。typedef 名字可以出现在任何类型名能够出现的地方

// typedef 名字可以被用作程序文档的辅助说明，它也能够降低声明的复杂度。例如，在典型情况下，typedef 名字可以
// 用来增强 "复杂模板声明的定义" 的可读性，增强 "指向函数的指针" 以及 "指向类的成员函数的指针" 的可读性

// 下面是一个几乎所有人刚开始都会打错的问题，错误在于将 typedef 当作宏扩展。已知下面的 typedef:
typedef char *cstring;
// 在以下声明中，cstr 的类型是什么？
extern const cstring cstr;
// 第一个回答差不多都是：const char *cstr 即指向 const 字符的指针。但是，这是不准确的。const 修饰 cstr 的类型。
// cstr 是一个指针，因此，这个定义声明了 cstr 是一个指向字符的 const 指针 char *const cstr;

int main(void)
{
	const int class_size = 16;

	// double hourly, weekly;
	wages hourly, weekly;

	// vector<int> vec1(10);
	vec_int vec1(10);

	// vector<bool> attendance;
	vector<in_attendance> attendance(class_size);

	// int *table[10];
	Pint table[10];

	hourly = 1.0;
	weekly = 1.0;

	table[0] = 0;

	cout << hourly << " " << weekly << " " << table[0] << endl;


	return 0;
}
