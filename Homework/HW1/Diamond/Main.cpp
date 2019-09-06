/*
Luke Underwood
9/5/2019
Diamond
Prints a diamond of #'s of a size determined by user input
*/
#include <iostream>

int main()
{
	int input;	//holds the user's input
	int lines;	//uses input to determine number of lines
	int countL;	//counts lines in for loop
	int countS;	//counts spaces in for loop
	int countH;	//counts hashes in for loop

	std::cout << "Please enter an integer to determine your diamond's size" << std::endl;
	std::cin >> input;
	lines = (2 * input) - 2;	//bases number of lines tall the diamond will be on number of #'s wide (starting from 0)


	if (input >= 1)										//Checks for valid input. Not sure why this works for characters, but it does
	{
		for (countL = 0; countL <= lines; countL++)		//This for loop iterates once per line of the diamond
		{
			if (countL < input)							//Checks if we are on the waxing or waning half of the diamond
			{ 
					//-------------------------------------------------WAXING HALF-----------------------------------------------------------//

				for (countS = 0; countS <= input - (countL + 2); countS++)	//prints a number of spaces before the hashes begin
					std::cout << " ";
				for (countH = 0; countH <= countL * 2; countH++)			//prints the appropriate number of hashes for the current line
					std::cout << "#";
				std::cout << std::endl;										//moves on to the next line
			}
			else 
			{ 
					//-------------------------------------------------WANING HALF------------------------------------------------------------//

				for (countS = 0; countS <= countL - input; countS++)		//prints a number of spaces before the hashes begin
					std::cout << " ";
				for (countH = 0; countH <= (lines - countL) * 2; countH++)	//prints the appropriate number of hashes for the current line
					std::cout << "#";
				std::cout << std::endl;										//moves on to the next line
			}
		}
	}
	else		//Error message for invalid input
	{
		std::cout << "ERROR: PLEASE RESTART THE PROGRAM AND ENTER AN INTEGER GREATER THAN 0";
	}

	return 0;
}