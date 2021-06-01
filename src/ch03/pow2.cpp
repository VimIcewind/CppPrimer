#include <iostream>

using namespace std;

extern int pow(int, int);

int main()
{
	int val = 2;
	int exp = 15;

	cout << "The Powers of 2\n";

	for (int cnt = 0; cnt <= exp; ++cnt)
		cout << cnt << ": " << pow(val, cnt) << endl;

	return 0;
}
