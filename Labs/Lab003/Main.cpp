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

	//--------------------------|Part 1|------------------------------
	//counts from 1-20. prints each number and moves to the next line
	while (count <= 20)
	{
		std::cout << count << std::endl;
		count++;
	}


	//--------------------------|Part 2|------------------------------
	//counts rows
	while (row < 10)
	{
		//counts columns
		while (column < 60)
		{
			//adds a hash and moves to the next column
			std::cout << "#";
			column++;
		}

		//moves to next line and resets column counter
		std::cout << std::endl;
		row++;
		column = 0;
	}

	//sets up for part 3
	row = 0;
	column = 0;
	std::cout << std::endl;

	//--------------------------|Part 3|------------------------------
	//counts rows
	while (row < 10)
	{
		//counts columns
		while (column < 30)
		{
			//adds a hash and moves to the next column
			std::cout << "|#";
			column++;
		}

		//moves to next line and resets column counter
		std::cout << std::endl;
		row++;
		column = 0;
	}
	return 0;
}