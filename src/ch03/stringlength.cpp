#include <iostream>

using namespace std;

const char *st = "The expense of spirit\n";

int string_length(const char *st)
{
	int cnt = 0;

	if (st)
		while (*st++)
			++cnt;
	return cnt;
}

int main(void)
{
	int len = 0;

	len = string_length(st);
	cout << len << ": " << st;

	return 0;
}
