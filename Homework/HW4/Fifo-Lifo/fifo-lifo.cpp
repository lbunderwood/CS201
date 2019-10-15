// Luke Underwood
// 10/15/19
// fifo-lifo.cpp
// Program that demonstrates the difference between lifo (last in first out)
// and fifo (first in first out)

#include"Header.h"

int main()
{
	//initialize variables
	int menuchoice = 0;
	std::string item;
	std::vector<std::string> container;

	//welcome message
	std::cout << "Welcome to fifo-lifo, a program that enables you to store "
		<< "text in a database and manipulate it by either first-in-first-out "
		<< "(fifo) or last-in-first-out (lifo)." << std::endl;

	while (menuchoice != 7)
	{
		//menu output/input
		std::cout << std::endl
			<< "Please enter a number to choose an option:\n"
			<< "\t1. Add an entry to the front (fifo)\n"
			<< "\t2. Add an entry to the end (lifo)\n"
			<< "\t3. Remove the first entry added (fifo)\n"
			<< "\t4. Remove the last entry added (lifo)\n"
			<< "\t5. Print all of the entries\n"
			<< "\t6. Test fifo and lifo\n"
			<< "\t7. Exit" << std::endl;
		std::cin >> menuchoice;
		std::cout << std::endl;

		//check for good input
		if (menuchoice < 1 || menuchoice > 7)
		{
			std::cout << "Please enter a valid option" << std::endl;
			continue;
		}

		//menu operation
		switch (menuchoice)
		{
		case 1: //fifopush
			std::cout << "Enter the text you would like to add: ";
			std::cin.ignore();
			std::getline(std::cin, item);
			fifoPush(container, item);
			break;
		case 2: //lifopush
			std::cout << "Enter the text you would like to add: ";
			std::cin.ignore();
			std::getline(std::cin, item);
			lifoPush(container, item);
			break;
		case 3: //fifopop
			fifoPop(container);
			break;
		case 4: //lifopop
			lifoPop(container);
			break;
		case 5: //print everything
			printContainer(container);
			break;
		case 6: //diagnostics
			if (fifoTest())
			{
				std::cout << "Fifo works." << std::endl;
			}
			else
			{
				std::cout << "Fifo is broken." << std::endl;
				menuchoice = 7;
			}

			if (lifoTest())
			{
				std::cout << "Lifo works." << std::endl;
			}
			else
			{
				std::cout << "Lifo is broken." << std::endl;
				menuchoice = 7;
			}
			break;
		case 7: //exit
			break;
		}
	}
}