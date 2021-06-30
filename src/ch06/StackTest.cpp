#include <iostream>
#include "Stack.h"

using namespace std;
using namespace Primer_Third_Edition;

int main()
{
	Stack<int> stack(32);

	stack.display();
	for (int ix = 1; ix < 51; ++ix) {
		if (ix % 2 == 0)
			stack.push(ix);
		if (ix % 5 == 0) {
			int dummy;
			stack.display();
			stack.peek(dummy);
		}
		if (ix % 10 == 0) {
			int dummy;
			stack.pop(dummy);
			stack.pop(dummy);
			stack.display();
		}
	}

	return 0;
}
