#include <iostream>
#include <string>

using namespace std;

int main()
{
	string quote1("When lilacs last in the dooryard bloom's");
	string quote2("The child is father of the man");
	string sentence;

	sentence.assign(quote2.c_str(), 13);
	sentence.append(quote1.c_str()+17, 15);
	cout << "sentence is '" << sentence <<"'\n";

	return 0;
}
