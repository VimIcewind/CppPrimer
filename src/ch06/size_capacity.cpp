#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec;

	cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	for (int ix = 0; ix < 24; ++ix) {
		ivec.push_back(ix);
		cout << "ivc: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	}


	return 0;
}

