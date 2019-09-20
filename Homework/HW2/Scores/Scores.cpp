/*
Luke Underwood
9/20/19
Scores.cpp
Stores pairs of names and scores as vectors and allows the user to search them,
print them, or add new ones.
*/

#include<iostream>
#include<vector>
#include<string>
#include"scoreheader.h"

int main()
{
	//initializes variables
	int menuchoice = 0;
	std::string search;
	std::vector<std::string> names;
	std::vector<std::string> scores;

	//collects names to get things started
	inputScores(names, scores);

	//will end the program if the user inputs a 5
	while (menuchoice != 5)
	{
		//prints a little menu
		std::cout << "Please enter a number to choose an option\n"
			<< "	1. Enter new scores\n"
			<< "	2. Print all of the names and scores\n"
			<< "	3. Search for a name\n"
			<< "	4. Search for a score\n"
			<< "	5. Exit the program\n";
		std::cin >> menuchoice;

		//executes a different function for each menu option
		switch (menuchoice)
		{
		case 1:
			inputScores(names, scores);
			break;
		case 2:
			printScores(names, scores);
			break;
		case 3:
			std::cout << "Please enter the name you would like to search for\n";
			std::cin >> search;
			if (searchNames(names, search))
			{
				std::cout << "That name is on file!\n";
			}
			else {
				std::cout << "That name is not on file\n";
			}
			break;
		
		case 4:
			std::cout << "Please enter the score you would like to search for\n";
			std::cin >> search;
			if (searchNames(scores, search))
			{
				std::cout << "That score is on file!\n";
			}
			else {
				std::cout << "That score is not on file\n";
			}
			break;
		case 5:
			break;
		}
	}

	return 0;
}