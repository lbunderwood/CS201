/*
Luke Underwood
9/23/19
Collatz.cpp
Takes an int from the user and outputs the collatz sequence for that number
*/

#include<iostream>

int main()
{
	int number = 0;

	while (number <= 0)
	{
		std::cout << "Please input an integer: ";
		std::cin >> number;
		if (number <= 0)
		{
			std::cout << "Please choose something larger than 0!" << std::endl;
		} else {
			std::cout << std::endl << number << " ";
		}
		
	}
	
	while (number != 1)
	{
		switch (number % 2)
		{
		case 0:
			number /= 2;
			std::cout << number << " ";
			break;
		case 1:
			number = number * 3 + 1;
			std::cout << number << " ";
			break;
		}
	}
}