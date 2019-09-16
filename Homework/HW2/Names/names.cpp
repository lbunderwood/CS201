/*
Luke Underwood
9/16/19
names.cpp
Uses functions to collect names from user and do a number of things with them
*/

#include<iostream>;
#include<vector>;
#include<string>;
#include<algorithm>;
#include"nameheader.h";

int main()
{
	int menuchoice = 0;
	
	inputNames();
	while (menuchoice != 5)
	{
		std::cout << "Please enter a number to choose an option\n"
			<< "	1. Enter new names\n"
			<< "	2. Check if a name is in the list\n"
			<< "	3. Prints the names\n"
			<< "	4. Sort the names alphabetically\n"
			<< "	5. Exit the program";
		std::cin >> menuchoice;

		switch (menuchoice)
		{
		case 1:
			inputNames();
			break;
		case 2:
			searchNames();
			break;
		case 3:
			printNames();
			break;
		case 4:
			sortNames();
			break;
		case 5:
			break;
		}


	}
	

	
	return 0;
}
