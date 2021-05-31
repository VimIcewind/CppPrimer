#include <iostream>
#include <cassert>
#include "IntArray.h"
#include "IntArrayRC.h"
using namespace std;

void swap(IntArray&, int, int);

int main(int argc, char *argv[])
{
	int array[4] = {0, 1, 2, 3};
	IntArray ia1(array, 4);
	IntArrayRC ia2(array, 4);

	cout << "swap() with IntArray ia1" << endl;
	swap(ia1, 1, ia1.size());

	cout << "swap() with IntArrayRC ia2" << endl;
	swap(ia2, 1, ia2.size());

	return 0;
}

void swap(IntArray &ia, int i, int j)
{
	int temp;

	temp = ia[i];
	ia[i] = ia[j];
	ia[j] = temp;
}
