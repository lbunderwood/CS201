/*
Luke Underwood
9/30/19
userInput.cpp
Holds functions for userInputMain.cpp
*/

#include "userInput.hpp"

void getUserStrings(std::vector<std::string>& words)
{
	std::string word;
	do
	{
		std::cin >> word;
		words.push_back(word);
	} while (words.back() != "end");
}