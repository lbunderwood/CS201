// Luke Underwood
// Bitwise.cpp
// Lab 36
// CS201
// 12/2/19

#include<iostream>
#include<cmath>

const int ZERO = 1;
const int ONE = 2;
const int TWO = 4;
const int THREE = 8;
const int FOUR = 16;

void bitwise(int input)
{
	for (int i = 4; i >= 0; i--)
	{
		if (input & (int)pow(2, i))
		{
			std::cout << "1";
		}
		else
		{
			std::cout << "0";
		}
	}
	if (input & 3)
	{
		std::cout << std::endl << "Both 2^0 and 2^1 == true";
	}

}


int main()
{
	std::cout << "2^0 | 2^1 = ";
	bitwise(ZERO | ONE);
	std::cout << std::endl;

	std::cout << "2^2 | 2^4 = ";
	bitwise(TWO | FOUR);
	std::cout << std::endl;

	std::cout << "2^0 | 2^1 | 2^2 | 2^3 | 2^4 = ";
	bitwise(ZERO | ONE | TWO | THREE | FOUR);
	std::cout << std::endl;

	std::cout << " 0 = ";
	bitwise(0);
	std::cout << std::endl;

}