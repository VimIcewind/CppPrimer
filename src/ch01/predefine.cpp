#include <iostream>

using namespace std;

int main(void)
{
	int element_count = 0;

	if (element_count == 0)
		cerr << __DATE__ << " " << __TIME__
			<< " Error: " << __FILE__
			<< " : line " << __LINE__ << " --> "
			<< "element_count must be non-zero.\n";

	return 0;
}
