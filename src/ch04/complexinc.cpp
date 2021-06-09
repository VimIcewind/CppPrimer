#include <iostream>
#include <complex>

using namespace std;

inline complex<double>& operator++(complex<double> &cval)
{
	return cval += complex<double>(1);
}

inline complex<double> operator++(complex<double> &cval, int)
{
	complex<double> oldcval = cval;
	cval += complex<double>(1);
	return oldcval;
}

int main()
{
	complex<double> cval(4.0, 1.0);

	cout << cval << endl;
	++cval;
	cout << cval << endl;
	cout << cval++ << endl;
	cout << cval << endl;

	return 0;
}

