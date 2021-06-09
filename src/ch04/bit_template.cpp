#include <iostream>

using namespace std;

template <class Type>
inline bool bit_on(Type ui, int pos)
{
	return ui & (1 << pos);
}

template <class Type>
inline void bit_turn_on(Type &ui, int pos)
{
	ui |= (1 << pos);
}

template <class Type>
inline void bit_turn_off(Type &ui, int pos)
{
	ui &= ~(1 << pos);
}

template <class Type>
inline void flip_bit(Type &ui, int pos)
{
	ui ^= (1 << pos);
}

template <class Type>
inline bool bit_off(Type &ui, int pos)
{
	return !bit_on(ui, pos);
}

int main()
{
	unsigned int ui = 0xd3;	// 1101 0011 in binary
				// bits are numbered from the right
				// starting at postion 0
	cout << "ui in hex: " << hex << ui << endl;

	// turn on the 4th bit from the right
	bit_turn_on(ui, 3);
	cout << "result should be 'db', it is " << hex << ui << endl;

	// turn off the 4th bit from the right
	bit_turn_off(ui, 3);
	cout << "result should be 'd3', it is " << hex << ui << endl;

	// flip the 4th bit from the right
	flip_bit(ui, 3);
	cout << "result should be 'db', it is " << hex << ui << endl;

	// flip the 4th bit from the right
	flip_bit(ui, 3);
	cout << "result should be 'd3', it is " << hex << ui << endl;

	cout << "4th bit should be 0, it is " << bit_on(ui, 3) << endl;

	cout << "1st bit should be 1, it is " << bit_on(ui, 0) << endl;

	return 0;
}
