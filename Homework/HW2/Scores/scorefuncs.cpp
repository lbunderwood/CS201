/*
Luke Underwood
9/20/19
scorefuncs.cpp
Holds function definitions
*/

#include<iostream>
#include<vector>
#include<string>
#include"scoreheader.h"

//takes the input from the user
void inputScores(std::vector<std::string>& names, std::vector<std::string>& scores)
{
	int i = 0;

	//clears out existing names so we can start fresh
	names.clear();

	for (i = 0; i < 10; i++)
	{
		std::string name;
		std::cout << "Please enter name " << i + 1 << std::endl;
		std::cin >> name;
		names.push_back(name);
	}
}

//prints the names
void printScores(std::vector<std::string>& names, std::vector<std::string>& scores)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		std::cout << names[i] << std::endl;
	}
}

//searches the names
bool searchNames(std::vector<std::string>& names, std::string search)
{
	int i = 0;
	bool exists = false;

	for (i = 0; i < 10; i++)
	{
		if (names[i] == search)
		{
			exists = true;
		}
	}
	return exists;
}

//searches the scores
bool searchScores(std::vector<std::string>& scores, std::string search)
{
	int i = 0;
	bool exists = false;

	for (i = 0; i < 10; i++)
	{
		if (scores[i] == search)
		{
			exists = true;
		}
	}
	return exists;
}