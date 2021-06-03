#include <iostream>

using namespace std;

const char *st = "The expense of spirit\n";

int main()
{
	int len = 0;
	const char *p = st;

	while (*p++)
		++len;
	cout << len << ": " << st;

	return 0;
}
