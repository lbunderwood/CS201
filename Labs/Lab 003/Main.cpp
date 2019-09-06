/*
Luke Underwood
9/9/2019
Lab 003
Uses while loops to print 1-20 and a 60x10 box of characters
*/

#include <iostream>

int main()
{
	//set up some variables
	int count = 1;
	int row = 0;
	int column = 0;

	//counts from 1-20. prints each number and moves to the next line
	while(count<=20)
	{
		std::cout << count << std::endl;
		count++;
	}

	//counts rows
	while(row < 10)
	{
		//counts columns
		while (column < 60)
		{
			std::cout << "#";
			column++;
		}
		std::cout << std::endl;
		row++;
	}
	return 0;
}