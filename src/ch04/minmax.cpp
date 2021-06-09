#include <iostream>

using namespace std;

int main()
{
	int i = 10, j = 20, k = 30;

	cout << "The larger value of "
		<< i << " and " << j << " is "
		<< (i > j ? i : j) << endl;

	cout << "The value of " << i << " is"
		<< (i % 2 ? " odd." : " even.")
		<< endl;

	int max = ((i > j) ? ((i > k) ? i : k) : (j > k) ? j : k);

	cout << "The larger value of "
		<< i << ", " << j << " and " << k
		<< " is " << max << endl;

	return 0;
}
