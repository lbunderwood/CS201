// Luke Underwood
// 10/15/19
// fifo-lifo.cpp
// Program that demonstrates the difference between lifo (last in first out)
// and fifo (first in first out)

#include"Header.h"

int main()
{
	int menuchoice = 0;
	std::string item;
	std::vector<std::string> container;

	std::cout << "Welcome to fifo-lifo, a program that enables you to store "
		<< "text in a database and manipulate it by either first-in-first-out "
		<< "(fifo) or last-in-first-out (lifo)." << std::endl;

	while (menuchoice != 5)
	{
		//menu output/input
		std::cout << "Please enter a number to choose an option:\n"
			<< "\t1. Add an entry\n"
			<< "\t2. Remove the first entry added (fifo)\n"
			<< "\t3. Remove the last entry added (lifo)\n"
			<< "\t4. Print all of the entries\n"
			<< "\t5. Exit" << std::endl;
			std::cin >> menuchoice;

		//check for good input
		if (menuchoice < 1 || menuchoice > 5)
		{
			std::cout << "Please enter a valid option" << std::endl;
			continue;
		}

		switch (menuchoice)
		{
		case 1:
			std::cout << "Enter the text you would like to add: ";
			std::getline(std::cin, item);
			Push(container, item);
			break;
		case 2:
			fifoPop(container);
			break;
		case 3:
			lifoPop(container);
			break;
		case 4:
			printContainer(container);
			break;
		case 5:
			break;
		}


	}
		
}