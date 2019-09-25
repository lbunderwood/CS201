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
	//initialize variables
	std::string message;
	int num = 0;

	while(true)
	{
		//prints prompts, collects info
		std::cout << "Enter exit, then 0 to end the program\n"
				  << "Please enter a string: ";
		getline(std::cin, message);

		std::cout << "Please enter an integer: ";
		std::cin >> num;

		//error handling and exit condition
		if(message == "exit" && num == 0)
		{
			break;
		} 
		else if (num < 0)
		{
			std::cout << "Please enter a positive number!\n";
		}
		else
		{
			boxPrint(message, num); //actually prints the box
		}

	}

	return 0;
}