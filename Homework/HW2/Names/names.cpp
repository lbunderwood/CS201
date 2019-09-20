/*
Luke Underwood
9/16/19
names.cpp
Uses functions to collect names from user and do a number of things with them
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"nameheader.h"

int main()
{
	//initializes variables
	int menuchoice = 0;
	std::string search;
	std::vector<std::string> names;

	//collects names to get things started
	inputNames(names);

	//will end the program if the user inputs a 5
	while (menuchoice != 5)
	{
		//prints a little menu
		std::cout << "Please enter a number to choose an option\n"
			<< "	1. Enter new names\n"
			<< "	2. Check if a name is in the list\n"
			<< "	3. Print the names\n"
			<< "	4. Print the number of characters in each name\n"
			<< "	5. Exit the program\n";
		std::cin >> menuchoice;

		//executes a different function for each menu option
		switch (menuchoice)
		{
		case 1:
			inputNames(names);
			break;
		case 2:
			std::cout << "Please enter the name you would like to search for\n";
			std::cin >> search;
			if (searchNames(names, search))
			{
				std::cout << "That name is on file!\n";
			} else {
				std::cout << "That name is not on file\n";
			}
			break;
		case 3:
			printNames(names);
			break;
		case 4:
			charNum(names);
			break;
		case 5:
			break;
		}


	}

	return 0;
}