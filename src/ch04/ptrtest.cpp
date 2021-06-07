#include <iostream>

using namespace std;

typedef struct Number {
	int value;
} Number;

bool notFound(int x)
{
	return x < 0 && x > 9;
}

int main()
{
	Number n;
	n.value = 2;
	Number *ptr = &n;
	int upperBound = 10;
	int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	while (ptr != 0 && ptr->value < upperBound && ptr->value >= 0 && notFound(ia[ptr->value])) {
		cout << "OK";
	}

	return 0;
}
