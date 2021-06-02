#include <iostream>

using namespace std;

void do_something()
{

}

void errorHandler()
{

}

int main()
{
	double dval = 3.14;
	const int bufSize = 512;
	const double *pc = 0;
	const double minWage = 9.60;
	const double *cptr = &minWage;

	if (bufSize == 0)
		cout << bufSize << endl;
	else
		for (int index = 0; index < bufSize; ++index)
			cout << index << " ";
	cout << endl << *cptr << endl;
	// *ptr += 1.40;
	// error: assignment of read-only location ‘ * ptr’

	pc = &minWage;
	cout << *pc << endl;

	pc = &dval;
	cout << *pc << endl;

	dval = 3.14159;

	// *pc = 3.14159;
	// error: assignment of read-only location ‘ * pc’

	int errNumb = 0;
	int *const curErr = &errNumb;

	do_something();

	if (*curErr) {
		errorHandler();
		*curErr = 0;
	}

	// int myErrNumb = 1;
	// curErr = &myErrNumb;
	// error: assignment of read-only variable ‘ curErr’

	const double pi = 3.14159;
	cout << pi << endl;

	const double *const pi_ptr = &pi;
	cout << *pi_ptr << endl;

	return 0;
}
