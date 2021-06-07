#include <iostream>

using namespace std;

int main()
{
	char byte_value = 32;
	int ival = 8;

	// overflow of byte_value's availiable memory
	byte_value = ival *byte_value;
	cout << "byte_value: " << static_cast<int>(byte_value) << endl;
	// byte_value: 0

	return 0;
}
