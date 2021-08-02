#include <iostream>

using namespace std;

void swap(int, int);

int main()
{
	int i = 10;
	int j = 20;

	cout << "Before swap():\ti: " << i << "\tj: " << j << endl;
	swap(i, j);
	cout << "After swap():\ti: " << i << "\tj: " << j << endl;

	return 0;
}

// swap() 没有交换两个实参的值
void swap(int v1, int v2)
{
	int tmp = v2;
	v2 = v1;
	v1 = tmp;
}
