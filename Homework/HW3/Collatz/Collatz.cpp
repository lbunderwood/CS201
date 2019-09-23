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

	std::cout << "Please input an integer: ";
	std::cin >> number;

	while (number != 1)
	{
		switch (number % 2)
		{
		case 0:
			break;
		case 1:
			break;
		}
	}
}