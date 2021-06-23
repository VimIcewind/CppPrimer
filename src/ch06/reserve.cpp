#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> svec;

	cout << svec.capacity() << endl;;
	// 0

	// 把容量设置为 32
	svec.reserve(32);

	cout << svec.capacity() << endl;;
	// 32

	return 0;
}
