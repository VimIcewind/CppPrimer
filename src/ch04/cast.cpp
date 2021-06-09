#include <iostream>
#include <string>
#include <cstring>
#include <complex>

using namespace std;

void mumble()
{
	int ival = 1024;
	void *pv;
	int *pi = &ival;
	const char *pc = "a casting call";

	pv = pi;
	// pc = pv;  // error: invalid conversion from 'void*'  to 'const char*'  [-fpermissive]
	// ok: 仍然是错误的，但是现在可以通过编译！
	// 因为在赋值前用了显式强制转换
	// 当程序失败时，应该首先检查强制转换
	pc = static_cast<char *>(pv);


	// 仍然是一个灾难
	char *pstr = new char[strlen(pc)+1];
	strcpy(pstr, pc);
}

void add()
{
	double dval = 3.14;
	int ival = 1;

	// 执行显式强制转换的第二个原因是希望改变通常的标准转换。例如，下列符合赋值，
	// 首先将 ival 提升成 double 型，然后再把它加到 dval 上，最后把结构截取成 int 型来执行赋值
	ival += dval;

	// 通过显式地将 dval 强制转换成 int 型，消除了把 ival 从 int 型到 double 型的不必要提升
	ival += static_cast<int>(dval);

	cout << ival << endl;
}

char *string_copy(char* s)
{
	// TODO do the copy
	return s;
}

void constcast()
{
	const char *pc_str = "const_cast";

	// const_cast 将转换掉表达式的常量性 以及 volatile 对象的 volatile 性
	char *pc = string_copy(const_cast<char*>(pc_str));
	// 试图用其他三种形式来转换掉常量性会引起编译错误。类似地，用 const_cast 来执行一般的类型转换，
	// 也会引起编译错误

	cout << pc << endl;
}

void reinterprecast()
{
	complex<double> com(1.0, 1.0);
	complex<double> *pcom = &com;
	// reinterpret_cast 通常对于操作数的位模式执行一个比较低层次的重新解释，它的正确性
	// 很大程度上依赖于程序员的主动管理。例如，下列转换：
	char *pc = reinterpret_cast<char*>(pcom);
	// 程序员必须永远也不会失去对 pc 实际指向对象的监视。例如，把它传递给一个 String 对象
	string str(pc);
	// 可能会引起 str 运行时的古怪行为

	cout << pcom << endl;
	cout << pc << endl;
	cout << str << endl;
}

void dynamiccast()
{
	// dynamic_cast 支持在运行时刻识别由指针或引用指向的类对象
}

char *rewrite_str(char *s)
{
	return s;
}

void oldcast()
{
	// C++ 前置转换符号
	// type (expr);

	// C 语言强制转换符号
	// (type) expr;

	complex<double> com(1.0, 1.0);
	complex<double> *pcom = &com;

	const char *pc = (const char*) pcom;
	int ival = (int) 3.14159;

	char *pc2 = rewrite_str((char *) pc);
	// int addr_value = int(&ival);
	long addr_value = long(&ival);

	cout << pc << endl;
	cout << pc2 << endl;
	cout << addr_value << endl;
}

int main()
{
	double dval = 8.6;
	int ival = 5;
	ival += dval + 0.5;

	cout << ival << endl;

	ival = static_cast<int>(3.541) + 3;

	cout << ival << endl;

	return 0;
}
