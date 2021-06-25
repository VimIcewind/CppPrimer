#include <iostream>
#include <string>

using namespace std;

string generate_salutation(string generic1,
		string lastName,
		string generic2,
		string::size_type pos,
		int length)
{
	generic1.replace(8, 5, lastName);

	generic1.replace(5, 2, generic2, pos, length);

	return generic1;
}

int main()
{
	string generic1("Dear Ms Daisy");
	string generic2("MrsMsMissPeople");
	string lastName("AnnaP");
	string greetings = generate_salutation(generic1, lastName, generic2, 5, 4);

	cout << greetings << endl;

	return 0;
}
