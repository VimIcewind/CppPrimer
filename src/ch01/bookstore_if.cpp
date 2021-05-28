#include <iostream>
using namespace std;

int read()
{
	int count;

	cout << "read()\n";
	return count;
}

void sort()
{
	cout << "sort()\n";
}

void compact()
{
	cout << "compact()\n";
}

void write()
{
	cout << "write()\n";
}

int main()
{
	int count = read();

	if (count > 1) {
		sort();
		compact();
	}
	if (count == 0)
		cout << "no sales for this month\n";
	else
		write();

	return 0;
}
