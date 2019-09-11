/*
Luke Underwood
9/11/2019
Lab 4
Prints numbers in sequence, but makes a couple changes
*/
#include <iostream>

int main()
{
	//set up variables
	int counter = 1;

	//straight forward for loop. Iterates from 1 to 100
	for (counter = 1; counter <= 100; counter++)
	{
		//if its divisible by both...
		if (counter % 3 == 0 && counter % 5 == 0)
		{
			std::cout << "Fizz Buzz";
		}
		//if divisible by just 3...
		else if (counter % 3 == 0)
		{
			std::cout << "Fizz";
		}
		//if divisible by just 5...
		else if (counter % 5 == 0)
		{
			std::cout << "Buzz";
		}
		//if nothing else applies...
		else
		{
			std::cout << counter;
		}
		//put this at the end so it's only there once
		std::cout << std::endl;
	}
	return 0;
}