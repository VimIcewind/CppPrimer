#include <iostream>
#include "StringCount.h"

using namespace std;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
	theCnt = 0, itCnt = 0, wdCnt = 0, notVowel = 0;
	// 为了使用 operator==(const char *)
	// 我们并不定义 The ("The") 和 It ("It")
	String buf, the("the"), it("it");

	// 调用 operator>>(istream&, String&)
	while (cin >> buf) {
		++wdCnt;
		cout << buf << ' ';
		if (wdCnt % 12 == 0)
			cout << endl;
		// 调用 String::operator==(const String&) and
		// String::operator==(const char*);
		if (buf == the || buf == "The")
			++theCnt;
		else
			if (buf == it || buf == "It")
				++itCnt;

		aCnt += buf.count('a');
		aCnt += buf.count('A');
		eCnt += buf.count('e');
		eCnt += buf.count('E');
		iCnt += buf.count('i');
		iCnt += buf.count('I');
		oCnt += buf.count('o');
		oCnt += buf.count('O');
		uCnt += buf.count('u');
		uCnt += buf.count('U');
	}

	// 调用 operator<<(ostream&, const String&)
	cout << "\n\n"
		<< "Words read: " << wdCnt << "\n\n"
		<< "the/The: " << theCnt << "\n\n"
		<< "it/It: " << itCnt << "\n\n"
		<< "a: " << aCnt << '\n'
		<< "e: " << eCnt << '\n'
		<< "i: " << iCnt << '\n'
		<< "o: " << oCnt << '\n'
		<< "u: " << uCnt << endl;

	return 0;
}
