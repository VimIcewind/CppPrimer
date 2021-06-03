#include <iostream>

using namespace std;

int foobar(int *pi) {
	if (pi) {
		*pi = 1024;
		return *pi;
	} else {
		return 0;
	}
}

int main()
{
	int ival2 = 0;
	int ival = foobar(&ival2);

	return 0;
}
