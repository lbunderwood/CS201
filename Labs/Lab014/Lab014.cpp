/*
Luke Underwood
10/4/19
Lab014.cpp
Contains the main function for a program that shrinks a user inputted string
*/

#include"Header014.h"

int main()
{
	std::string input;

	std::cout << "Please enter a word: ";
	std::cin >> input;

	shrinking(input);

	return 0;
}