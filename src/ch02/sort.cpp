#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ia[10] = {51, 23, 7, 88, 41, 98, 12, 103, 37, 6};

void display(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vec(ia, ia+10);

	sort(vec.begin(), vec.end());

	int search_value;
	cin >> search_value;

	vector<int>::iterator found;
	found = find(vec.begin(), vec.end(), search_value);
	if (found != vec.end())
		cout << "search_value found!\n";
	else
		cout << "search_value not found!\n";

	display(vec);
	reverse(vec.begin(), vec.end());
	display(vec);

	return 0;
}
