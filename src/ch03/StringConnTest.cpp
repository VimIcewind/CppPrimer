#include <iostream>
#include "StringConn.h"

using namespace std;

int main()
{
	String empty;
	String str1("The cow ");
	String str2("jumped over the moon.");
	String str3 = str1 + str2;

	cout << "String 1: |" << str1 << "|\n";
	cout << "String 2: |" << str2 << "|\n";

	// 测试空字符串的链接
	str3 = str3 + empty;
	str3 = empty + str3;

	cout << "String 1 + String 2: |" << str3 << "|\n";

	return 0;
}
