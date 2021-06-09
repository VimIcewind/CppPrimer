#include <iostream>
#include <complex>

using namespace std;

/*
inline complex<double>& operator+=(complex<double> &cval, double dval)
{
	return cval += complex<double>(dval);
}

inline complex<double>& operator-=(complex<double> &cval, double dval)
{
	return cval -= complex<double>(dval);
}

inline complex<double>& operator*=(complex<double> &cval, double dval)
{
	return cval *= complex<double>(dval);
}

inline complex<double>& operator/=(complex<double> &cval, double dval)
{
	return cval /= complex<double>(dval);
}
*/

int main()
{
	complex<double> cval(4.0, 1.0);

	cout << cval << endl;
	cval += 1;
	cout << cval << endl;
	cval -= 1;
	cout << cval << endl;
	cval *= 1;
	cout << cval << endl;
	cval /= 1;
}
