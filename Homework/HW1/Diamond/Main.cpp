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

	std::cout << "Please enter an integer to determine your diamond's size" 
			  << std::endl;
	std::cin >> input;
	//bases number of lines tall the diamond will be on user input
	lines = (2 * input) - 2;	

	//Checks for valid input. Not sure why this works for characters, but it does
	if (input >= 1)										
	{	
		//This for loop iterates once per line of the diamond
		for (countL = 0; countL <= lines; countL++)		
		{
			//Checks if we are on the waxing or waning half of the diamond
			if (countL < input)							
			{ 
				//-------------------------WAXING HALF-----------------------//
				
				//prints a number of spaces before the hashes begin
				for (countS = 0; countS <= input - (countL + 2); countS++)	
					std::cout << " ";
				
				//prints the appropriate number of hashes for the current line
				for (countH = 0; countH <= countL * 2; countH++)			
					std::cout << "#";
				
				//moves on to the next line
				std::cout << std::endl;										
			}
			else 
			{ 
				//------------------------WANING HALF------------------------//
				
				//prints a number of spaces before the hashes begin
				for (countS = 0; countS <= countL - input; countS++)		
					std::cout << " ";
				
				//prints the appropriate number of hashes for the current line
				for (countH = 0; countH <= (lines - countL) * 2; countH++)	
					std::cout << "#";
				
				//moves on to the next line
				std::cout << std::endl;										
			}
		}
	}
	else		//Error message for invalid input
	{
		std::cout << "ERROR: PLEASE RESTART THE PROGRAM AND "
				  << "ENTER AN INTEGER GREATER THAN 0";
	}

	return 0;
}