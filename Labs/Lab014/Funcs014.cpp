/*
Luke Underwood
10/4/19
Lab014.cpp
Contains the functions for a program that shrinks a user inputted string
*/

#include "Header014.h"

void shrinking(std::string input)
{
	for (auto i = input.size(); i > 0; i--)
	{
		std::cout << input.substr(0,i) << std::endl;
	}
}