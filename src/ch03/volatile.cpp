#include <iostream>

using namespace std;

const int max_size = 16;

int main()
{
	// 当一个对象的值可能会在编译器的控制或监视之外被改变时，例如一个被系统时钟更新的变量，
	// 那么该对象应该声明成 volatile。因此，编译器执行的某些例行优化行为不能应用在已制定为
	// volatile 的对象上

	// volatile 限定修饰符的用法同 const 非常相似 -- 都是作为类型的附加修饰符
	volatile int display_register;
	// volatile Task *curr_task;
	volatile int ixa[max_size];
	// volatile Screen bitmap_buf;

	display_register = 0;
	ixa[0] = 0;
	cout << display_register << " " << ixa[0] << endl;

	return 0;
}
