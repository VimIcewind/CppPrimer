#include <iostream>
#include <string>

using namespace std;

int main()
{
	string river("Mississippi");
	string::size_type first_pos = river.find("is");
	string::size_type last_pos = river.rfind("is");

	cout << first_pos << " " << last_pos << endl;

	return 0;
}
