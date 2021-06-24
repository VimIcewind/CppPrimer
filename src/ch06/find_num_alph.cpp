#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s("ab2c3d7R4E6");
	string numerics("0123456789");
	string alphabetic("abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;

	// find each nmeric character using find_first_of()
	while ((pos = s.find_first_of(numerics, pos)) != string::npos)
		cout << "s[ " << pos << " ] = "  << s[pos++] << "\n";

	// find each nmeric character using find_first_not_of()
	pos = 0;
	while ((pos = s.find_first_not_of(alphabetic, pos)) != string::npos)
		cout << "s[ " << pos << " ] = "  << s[pos++] << "\n";

	// find each alphabet character using find_first_of()
	pos = 0;
	while ((pos = s.find_first_of(alphabetic, pos)) != string::npos)
		cout << "s[ " << pos << " ] = "  << s[pos++] << "\n";

	// find each alphabet character using find_first_not_of()
	pos = 0;
	while ((pos = s.find_first_not_of(numerics, pos)) != string::npos)
		cout << "s[ " << pos << " ] = "  << s[pos++] << "\n";

	return 0;
}
