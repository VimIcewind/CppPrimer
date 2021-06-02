#include <iostream>

using namespace std;

int main(void)
{
	char *pc1 = 0;
	const char *pc2 = "";

	cout << *pc1 << endl;
	cout << *pc2 << endl;

	return 0;
}
