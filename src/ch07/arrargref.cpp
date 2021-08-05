#include <iostream>

using namespace std;

void putValues(int (&arr)[10]);

int main()
{
	int k[10];

	putValues(k);

	return 0;
}

void putValues(int (&ia)[10])
{
	cout << "( 10 ) < ";
	for (int i = 0; i < 10; ++i) {
		cout << ia[i];

		if (i != 9)
			cout << ", ";
	}
	cout << " >\n";
}
