#include <iostream>
#include <vector>
using namespace std;

#define SIZE 8

int getSize()
{
	return SIZE;
}

void mumble()
{
	int size = getSize();
	vector<int> vec(size);

	vector<int>::iterator iter = vec.begin();

	for (int ix = 0; iter != vec.end(); ++iter, ++ix)
		*iter = ix;

	iter = vec.begin();
	for (int ix = 0; iter != vec.end(); ++iter, ++ix)
		cout << "vec[" << ix << "]" <<" = " << ix << endl;
}

int main(int argc, char *argv[])
{
	mumble();
	return 0;
}
