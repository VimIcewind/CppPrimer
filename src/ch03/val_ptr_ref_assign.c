#include <stdio.h>

int main()
{
	int i = 1;
	int *pi = &i;
	// int &ri = i;
	// error: expected identifier or ‘ (’  before ‘ &’  token
	int j = i;

	printf("%d\n", i);
	printf("%d\n", *pi);
	// printf("%d\n", ri);
	printf("%d\n", j);

	printf("%p\n", &i);
	printf("%p\n", pi);
	// printf("%p\n", &ri);
	printf("%p\n", &j);

	return 0;
}

