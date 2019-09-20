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
void inputScores(std::vector<std::string>& names, std::vector<int>& scores)
{
	int i = 0;
	std::string name;
	int score = 0;
	
	std::cout << "Enter NoName, then 0 to conclude input.\n";
	while (true)
	{
		std::cout << "Please enter name " << i + 1 << std::endl;
		std::cin >> name;
		if (searchNames(names, name, i))
		{
			std::cout << "That name is taken! Please try again.\n";
			break;
		} else {
			names.push_back(name);
		}

		std::cout << "Please enter score " << i + 1 << std::endl;
		std::cin >> score;
		scores.push_back(score);

		if (names[i] == "NoName" && scores[i] == 0)
		{
			names.erase(names.end() - 1);
			scores.erase(scores.end() - 1);
			break;
		}
		i++;
	}
}

//prints the names
void printScores(std::vector<std::string>& names, std::vector<int>& scores)
{
	for (int i = 0; i < names.size(); i++)
	{
		std::cout << names[i];
		for (int j = 0; j < 15 - names[i].size(); j++)
			std::cout << " ";
		std::cout << scores[i] << std::endl;
	}
}

//searches the names
bool searchNames(std::vector<std::string>& names, std::string searchs, int& searchi)
{
	for (int i = 0; i < names.size(); i++)
	{
		if (names[i] == searchs)
		{
			searchi = i;
			return true;
		}
	}
	return false;
}

//searches the scores
bool searchScores(std::vector<int>& scores, int& search)
{
	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i] == search)
		{
			search = i;
			return true;
		}
	}
	return false;
}