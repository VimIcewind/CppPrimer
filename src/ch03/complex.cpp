#include <iostream>
#include <complex>

using namespace std;

int main(void)
{
	// 纯虚数：0 + 7i
	complex<double> purei(0, 7);

	// 虚数部分缺省为 0: 3 + 0i
	complex<float> real_num(3);

	// 实部和虚部均缺省为 0： 0 + 0i
	complex<long double> zero;

	// 用另一个复数对象来初始化一个复数对象
	complex<double> purei2(purei);

	// 这里，附属对象有 float、double 或 long double 几种表示。

	// 我们也可以声明复数对象的数组：
	complex<double> conjugate[2] = {
		complex<double>(2, 3),
		complex<double>(2, -3)
	};

	// 我们也可以声明指针或引用：
	complex<double> *ptr = &conjugate[0];
	complex<double> &ref = *ptr;

	cout << ref << endl;;
	// (2, 3)

	return 0;
}
