#include <iostream>
#include <bitset>
#include <cassert>
#include <iomanip>

using namespace std;

void buildFibonacci(int fib[], int n)
{
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i < n; i++)
		fib[i] = fib[i-1] + fib[i-2];
}

void initFibonacci(bitset<32> &bv, int n)
{
	assert(n > 0 && n <= 32);

	int fib[32];
	buildFibonacci(fib, n);
	for (int i = 0; i < n; i++) {
		bv.set(fib[i]);
	}
}

int main()
{
	bitset<32> bv;
	initFibonacci(bv, 7);
	for (size_t i = 0; i < bv.size(); i++) {
		if (bv.test(i))
			cout << "bit " << setw(2) << i << " on\n";
	}

	return 0;
}
