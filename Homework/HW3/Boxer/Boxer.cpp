/*
Luke Underwood
9/23/19
Boxer.cpp
Uses functions to print some text in a box of a defined size

-----------------------------------------------
****I am just a poor boy
****Though my story's seldom told
****I have squandered my resistance
****For a pocket full of mumbles, such are promises
****All lies and jests
****Still a man hears what he wants to hear
****And disregards the rest

-------Simon and Garfunkel's The Boxer--------

----------------------------------------------
*/

#include"Boxer.h"

int main()
{
	std::string message;
	int num = 0;

	std::cout << "Please enter a string: ";
	std::cin >> message;

	std::cout << "Please enter an integer: ";
	std::cin >> num;

	boxPrint(message, num);

	return 0;
}