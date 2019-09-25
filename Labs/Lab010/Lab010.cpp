/*
Luke Underwood
9/25/19
Lab010.cpp
Using the bool type
*/

#include"isdiv3.h"

int main()
{
	int input = 1;
	int divisor = 0;

	for (int i = 0; i <= 40; i++)
	{
		if (isDiv(i, 3))
			std::cout << i << std::endl;
	}

	while(input != 0)
	{
		std::cout << "Please input a number to be divided (0 to exit): ";
		std::cin >> input;

		std::cout << "Please input a number to divide it by: ";
		std::cin >> divisor;

		if (isDiv(input, divisor))
		{
			std::cout << input << " is divisible by " << divisor
					<< "\nThis equals " << input / divisor << std::endl;
		}
		else
		{
			std::cout << input << " is not divisible by " << divisor 
					<< std::endl;
		}
	}
}