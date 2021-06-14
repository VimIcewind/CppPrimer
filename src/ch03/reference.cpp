#include <iostream>

using namespace std;

int main()
{
	int ival = 1024;
	int &refVal = ival;
	int *pi = &ival;
	int *&ptrVal2 = pi;
	int min_val = 0;

	cout << ival << endl;
	cout << refVal << endl;
	cout << *pi << endl;
	cout << *ptrVal2 << endl;

	refVal = min_val;
	cout << refVal << endl;
	cout << ival << endl;

	refVal += 2;
	cout << refVal << endl;
	cout << ival << endl;

	int ii = refVal;
	cout << ii << endl;

	int *pr = &refVal;
	cout << *pr << endl;

	// const 引用可以用不同类型的对象初始化（只要能从一种类型转换到另一种类型即可），
	// 也可以是不可寻址的值，例如文字常量。
	double dval = 3.14159;
	cout << dval << endl;
	// 仅对于 const 引用才是合法的
	const int &ir = 1024;
	const int &ir2 = dval;
	const double &dr = dval + 1.0;
	cout << ir << endl;
	cout << ir2 << endl;
	cout << dr << endl;
	// 同样的初始化对于非 const 引用是不合法的，将导致编译错误。
	// 原因有些微妙，需要适当作些解释
	// 引用在内部存放的是一个对象的地址，它是该对象的别名。对于不可寻址的值，如文字常量，以及不同类型的对象，
	// 编译器为了实现引用，必须生成一个临时对象，引用实际上指向该对象，但用户不能访问它。

	double d = 1024;
	const int &ri = d;
	// 编译器将其转换成：
	// int temp = d;
	// const int &ri = temp;

	cout << d << endl;
	cout << ri << endl;

	// 下面给出的例子很难在第一次就能正确声明。我们希望用一个 const 对象的地址来初始化一个引用。
	// 非 const 引用定义时非法的，将导致编译时刻错误：
	const int i = 1024;
	// int *&pi_ref = &i;
	// error: invalid conversion from ‘ const int*’  to ‘ int*’  [-fpermissive]
	// const int *&pi_ref = &i;
	// error: cannot bind non-const lvalue reference of type ‘ const int*&’  to an rvalue of type ‘ const int*’
	// 如果我们从右到左读上面这个定义，会发现 pi_ref 是一个指向定义为 const 的 int 型对象的指针。
	// 我们的引用不是指向一个常量，而是指向一个非常量指针，指针指向一个 const 对象。
	// 正确的定义如下：
	const int *const &pi_ref = &i;

	cout << i << endl;
	cout << *pi_ref << endl;

	// 指针和引用有两个主要区别：引用必须总是指向一个对象。如果用一个引用给另一个引用赋值，那么
	// 改变的是被引用的对象而不是引用本身。
	// 用 0 初始化 pi -- 即，pi 当前不指向任何对象。
	int pi0 = 0;
	// 但当我们写如下语句时：
	const int &ri0 = 0;

	// 引用的赋值是第二个不同。

	return 0;
}
