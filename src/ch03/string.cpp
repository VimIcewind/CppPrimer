#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string st("The expense of spirit\n");

int main(void)
{
	cout << "The size of "
		<< st
		<< "is " << st.size()
		<< " characters, including the newline\n";

	string st2; // 空字符串
	if (!st2.size())
		cout << "ok : st2 为空字符串" << endl;
	if (st2.empty())
		cout << "ok : st2 为空字符串" << endl;

	string st3(st);
	if (st == st3)
		cout << "st3 初始化为 st" << endl;

	// 使用赋值操作符来拷贝一个字符串
	st2 = st3;
	// 上面这条赋值语句，首先将 st2 相关联的存储区释放掉，然后再分配足够存储与 st3 相关联的字符的存储区，
	// 最后将与 st3 相关联的字符拷贝到该存储区中
	cout << "st2: " << st2;

	string s1("hello, ");
	string s2("world\n");
	string s3 = s1 + s2;
	cout << "s3: " << s3;

	s1 += s2;
	cout << "s1: " << s1;

	const char *pc = ", ";
	string sh("hello");
	string sw("world");

	string hw = sh + pc + sw + "\n";
	cout << hw;
	// 这种连接策略比较受欢迎，因为它使 sh 和 sw 处于一种更容易被重用的形式。
	// 这种方法能够生效是由于 string 类型能够自动将 C 风格的字符串转换成 string 对象。
	// 例如，这使得我们可以将一个 C 风格的字符串赋值给一个 string 对象
	string strobj;
	const char *pcstr = "a character array";
	strobj = pcstr;
	cout << strobj << endl;

	// 但是，反向的转换不能自动执行。对隐式地将 string 对象转换成 C 风格的字符串，string 类型没有提供支持。
	// 例如，下面试图用 sh 初始化 str，就会在编译时刻失败
	// char *str = sh;
	// error: cannot convert ‘std::string’ {aka ‘std::basic_string<char>’} to ‘char*’ in initialization

	// 为了实现这种转换，必须显式地调用名为 c_str() 的操作：
	// char *str = s1.c_str(); // 几乎是正确的，但是还差一点
	// error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
	// 名字 c_str() 代表了 string 类型 与 C 风格字符串 两种表示法之间的关系。字面意思是：给我一个 C 风格的
	// 字符串表示--即，指向字符数组起始处的字符指针。
	// 但是，这个初始化还是失败了。这次是由于另外一个不同的原因：为了防止字符数组被程序直接处理，c_str() 返回了
	// 一个指向常量数组的指针 const char *
	// str 被定义为非常量指针，所以这个赋值被标记为类型违例。正确的初始化如下：
	const char *str = sh.c_str();
	cout << str << endl;

	string disney("fa.disney.com");
	int size = disney.size();

	for (int ix = 0; ix < size; ++ix)
		if (disney[ix] == '.')
			disney[ix] = '_';
	cout << disney << endl;
	replace(disney.begin(), disney.end(), '_', '.');
	cout << disney << endl;

	return 0;
}
