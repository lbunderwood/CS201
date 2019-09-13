/*
Luke Underwood
9/13/19
Lab005

*/

#include<iostream>

int main()
{
	int input = 0;

	while (input != 4)
	{
		std::cout << "Please choose 1, 2, or 3\n";
		std::cout << "	1. pancake\n";
		std::cout << "	2. waffle\n";
		std::cout << "	3. water\n";
		std::cout << "	4. Exit\n";
		std::cin >> input;

		switch (input)
		{
		case 1:
			std::cout << "     ------\n";
			std::cout << "    /      \\ \n";
			std::cout << "   |        |\n";
			std::cout << "    \\      /\n";
			std::cout << "     ------\n";
			break;
		case 2:
			std::cout << "     -------\n";
			std::cout << "     | | | |\n";
			std::cout << "     -------\n";
			std::cout << "     | | | |\n";
			std::cout << "     -------\n";
			break;
		case 3:
			std::cout << "     -------\n";
			std::cout << "     \\-----/\n";
			std::cout << "      |   |\n";
			std::cout << "      |   |\n";
			std::cout << "      -----\n";
			break;
		case 4:
			break;
		}

	}
	return 0;

}