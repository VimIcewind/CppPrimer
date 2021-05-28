#include <iostream>

using namespace std;

int main(void)
{
	int iterations = 0;
	bool continue_loop = true;

	while (continue_loop != false) {
		iterations++;
		cout << "the while loop has executed "
			<< iterations << " times\n";

		if (iterations == 5)
			continue_loop = false;
	}
	return 0;
}
