#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
	char ch;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, consonantCnt = 0;
	int spaceCnt = 0, tabCnt = 0, lineCnt = 0;
	int ffCnt = 0, fiCnt = 0, flCnt = 0;

	cout << "Please input something:" << endl;
	while (cin.get(ch))
		switch (ch) {
		case 'a': case 'A':
			++aCnt;
			break;
		case 'e': case 'E':
			++eCnt;
			break;
		case 'i': case 'I':
			++iCnt;
			break;
		case 'o': case 'O':
			++oCnt;
			break;
		case 'u': case 'U':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++lineCnt;
			break;
		case 'f':
			++consonantCnt;
			cin.get(ch);
			switch (ch) {
			case 'f':
				++consonantCnt;
				++ffCnt;
				break;
			case 'i':
				++iCnt;
				++fiCnt;
				break;
			case 'l':
				++consonantCnt;
				++flCnt;
				break;
			default:
				cin.putback(ch);
				break;
			}
			break;
		default:
			if (isalpha(ch))
				++consonantCnt;
			break;
		}
	cout << "Number of vowel a or A:\t" << aCnt << '\n'
		<< "Number of vowel e or E:\t" << eCnt << '\n'
		<< "Number of vowel i or I:\t" << iCnt << '\n'
		<< "Number of vowel o or O:\t" << oCnt << '\n'
		<< "Number of vowel u or U:\t" << uCnt << '\n'
		<< "Number of space:\t" << spaceCnt << '\n'
		<< "Number of tab:\t" << tabCnt << '\n'
		<< "Number of line:\t" << lineCnt << '\n'
		<< "Number of ff sequences:\t" << ffCnt << '\n'
		<< "Number of fi sequences:\t" << fiCnt << '\n'
		<< "Number of fl sequences:\t" << flCnt << '\n'
		<< "Number of consonants:\t" << consonantCnt << '\n';

	return 0;
}
