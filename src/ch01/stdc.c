#include <stdio.h>

#ifdef __STDC__
#define LANGUAGE "C"
#else
#define LANGUAGE "C++"
#endif

int main(void)
{
	printf("%s\n", LANGUAGE);
}
