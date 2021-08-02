#include <iostream>

using namespace std;

inline int abs(int iobj)
{
	return (iobj < 0 ? -iobj : iobj);
}

inline int min(int p1, int p2)
{
	return (p1 < p2 ? p1 : p2);
}

int gcd (int v1, int v2)
{
	while (v2) {
		int temp = v2;
		v2 = v1 % v2;
		v1 = temp;
	}
	return v1;
}

int main()
{
	// get values from standard input
	cout << "Enter first value: ";
	int i;
	cin >> i;
	if (!cin) {
		cerr << "!<< Oops: input error - Bailing out!\n";
		return -1;
	}
	cout << "Enter second value: ";
	int j;
	cin >> j;
	if (!cin) {
		cerr << "!<< Oops: input error - Bailing out!\n";
		return -2;
	}
	cout << "\nmin: " << min(i, j) << endl;
	i = abs(i);
	j = abs(j);
	cout << "gcd: " << gcd(i, j) << endl;

	return 0;
}
