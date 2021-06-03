#include <iostream>
#include "StringInit.h"

using namespace std;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
	bCnt = 0, dCnt = 0, fCnt = 0, sCnt = 0, tCnt = 0,
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

		// 调用 String::size()
		for (int ix = 0; ix < buf.size(); ++ix) {
			// 调用 String::operator[](int)
			switch(buf[ix]) {
			case 'a': case 'A': ++aCnt; break;
			case 'e': case 'E': ++eCnt; break;
			case 'i': case 'I': ++iCnt; break;
			case 'o': case 'O': ++oCnt; break;
			case 'u': case 'U': ++uCnt; break;
			case 'b': case 'B': ++bCnt; ++notVowel; break;
			case 'd': case 'D': ++dCnt; ++notVowel; break;
			case 'f': case 'F': ++fCnt; ++notVowel; break;
			case 's': case 'S': ++sCnt; ++notVowel; break;
			case 't': case 'T': ++tCnt; ++notVowel; break;
			default: ++notVowel; break;
			}
		}
	}

	// 调用 operator<<(ostream&, const String&)
	cout << "\n\n"
		<< "Words read: " << wdCnt << "\n\n"
		<< "the/The: " << theCnt << "\n\n"
		<< "it/It: " << itCnt << "\n\n"
		<< "non-vowels read: " << notVowel << "\n\n"
		<< "a: " << aCnt << '\n'
		<< "e: " << eCnt << '\n'
		<< "i: " << iCnt << '\n'
		<< "o: " << oCnt << '\n'
		<< "u: " << aCnt << '\n'
		<< "b: " << bCnt << '\n'
		<< "d: " << dCnt << '\n'
		<< "f: " << fCnt << '\n'
		<< "s: " << sCnt << '\n'
		<< "t: " << tCnt << endl;

	return 0;
}
