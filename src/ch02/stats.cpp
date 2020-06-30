#include <iostream>
#include <string>
#include <exception>
using namespace std;

int sum_it(const int *ia, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += ia[i];
	}
	return sum;
}

int min_val(const int *ia, int size)
{
	int min = ia[0];

	for (int i = 1; i < size; i++) {
		if (min > ia[i]) {
			min = ia[i];
		}
	}
	return min;
}

int max_val(const int *ia, int size)
{
	int max = ia[0];

	for (int i = 1; i < size; i++) {
		if (max < ia[i]) {
			max = ia[i];
		}
	}
	return max;
}

class statsException : public exception {
public:
	statsException() : message("statsException.") {
	}

	statsException(string str) : message("statsException : " + str) {
	}

	~statsException() throw () {
	}

	virtual const char* what() const throw () {
		return message.c_str();
	}

private:
	string message;
};

void do_something(const int *ia)
{
	throw statsException("do_something");
}

int * stats(const int *ia, int size)
{
	int *pstats = new int[4];

	try {
		pstats[0] = sum_it(ia, size);
		pstats[1] = min_val(ia, size);
		pstats[2] = max_val(ia, size);
	} catch (string exceptionMsg) {

	} catch (const statsException &stasExcep) {

	}

	pstats[3] = pstats[0]/size;
	do_something(pstats);

	return pstats;
}

int main(int argc, char *argv[])
{
	int ia[4] = {1, 2, 3, 4};
	int *pia = ia;

	try {
		cout << "Call stats..." << endl;
		pia = stats(ia, 4);
	} catch(statsException& e) {
		cout << e.what() << endl;
	} catch(std::exception& e) {
		cout << "Other exception." << endl;
	}
	return 0;
}
