#include <iostream>

using namespace std;

int main(void)
{
	const int rowSize = 4;
	const int colSize = 3;
	int ia[rowSize][colSize];

	for (int i = 0; i < rowSize; ++i)
		for (int j = 0; j < colSize; ++j)
			ia[i][j] = i + j;

	for (int i = 0; i < rowSize; ++i) {
		for (int j = 0; j < colSize; ++j)
			cout << ia[i][j] << "\t";
		cout << endl;
	}

	return 0;
}
