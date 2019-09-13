/*
Luke Underwood
9/13/19
Lab005
Prints some top-tier art based on your decision
*/

#include<iostream>

int main()
{
	int input = 0;

	//exits loop when user inputs 4
	while (input != 4)
	{
		//collects input
		std::cout << "Please choose 1, 2, or 3\n";
		std::cout << "	1. pancake\n";
		std::cout << "	2. waffle\n";
		std::cout << "	3. water\n";
		std::cout << "	4. Exit\n";
		std::cin >> input;

		switch (input)
		{
		case 1: //prints pancake
			std::cout << "     ------\n";
			std::cout << "    /      \\ \n";
			std::cout << "   |        |\n";
			std::cout << "    \\      /\n";
			std::cout << "     ------\n";
			break;
		case 2: //prints waffle
			std::cout << "     -------\n";
			std::cout << "     | | | |\n";
			std::cout << "     -------\n";
			std::cout << "     | | | |\n";
			std::cout << "     -------\n";
			break;
		case 3: //prints a glass of water
			std::cout << "     -------\n";
			std::cout << "     \\-----/\n";
			std::cout << "      |   |\n";
			std::cout << "      |   |\n";
			std::cout << "      -----\n";
			break;
		case 4: //just breaks switch statement, and 4 exits the loop
			break;
		}

	}
	return 0;

}