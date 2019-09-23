/*
Luke Underwood
9/23/19
BoxPrint.cpp
Contains function definitions for Boxer.cpp

-----------------------------------------------
****When I left my home and my family
****I was no more than a boy
****In the company of strangers
****In the quiet of the railway station
****Running scared,
****Laying low, seeking out the poorer quarters
****Where the ragged people go
****Looking for the places
****Only they would know

-------Simon and Garfunkel's The Boxer--------

----------------------------------------------
*/

#include"boxer.h"

void boxPrint(std::string message, int layers)
{
	int columns = message.size() + 2 * layers + 2; //total columns
	int rows = 2 * layers + 3;					   //total rows
	int countc = 1;								   //counter for columns
	int countr = 1;								   //counter for rows

	//prints the first chunk
	firstLast(layers, columns);
	middle(layers, columns);

	//prints the middle row with the text
	for (countc = 1; countc <= columns; countc++)
	{
		if (countc <= layers || countc > columns - layers)
			std::cout << "*";
		else if (countc == layers + 1 || countc == columns - layers)
			std::cout << " ";
		else
		{
			std::cout << message;
			countc += message.size() - 1;
		}
	}
	std::cout << std::endl;

	//prints the last chunk
	middle(layers, columns);
	firstLast(layers, columns);
}

//prints the purely asterisk lines at the beginning and end
void firstLast(int layers, int columns)
{
	for (int countr = 1; countr <= layers; countr++)
	{
		for (int countc = 1; countc <= columns; countc++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

//prints the lines around the text that have both asterisks and spaces
void middle(int layers, int columns)
{
	for (int countc = 1; countc <= columns; countc++)
	{
		if (countc <= layers || countc > columns - layers)
			std::cout << "*";
		else
			std::cout << " ";
	}
	std::cout << std::endl;
}