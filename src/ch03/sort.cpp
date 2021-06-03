#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ia[6] = {107, 28, 3, 47, 104, 76};
	string sa[3] = {"piglet", "eeyore", "pooh"};

	sort(ia, ia+6);
	sort(sa, sa+3);

	for (int i = 0; i < 6; i++) {
		cout << ia[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << sa[i] << ' ';
	}

	return 0;
}
