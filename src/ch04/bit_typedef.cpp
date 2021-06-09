#include <iostream>

using namespace std;

typedef unsigned int bitvec;

inline bool bit_on(bitvec ui, int pos)
{
	return ui & (1 << pos);
}

inline void bit_turn_on(bitvec &ui, int pos)
{
	ui |= (1 << pos);
}

inline void bit_turn_off(bitvec &ui, int pos)
{
	ui &= ~(1 << pos);
}

inline void flip_bit(bitvec &ui, int pos)
{
	ui ^= (1 << pos);
}

inline bool bit_off(bitvec &ui, int pos)
{
	return !bit_on(ui, pos);
}

int main()
{
	bitvec ui = 0xd3;	// 1101 0011 in binary
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
