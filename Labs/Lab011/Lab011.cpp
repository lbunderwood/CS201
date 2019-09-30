/*
Luke Underwood
9/27/19
Lab011.cpp

*/
#include <iostream>
#include <string>

int main()
{
	std::string input;

	while (true)
	{
		std::cout << "Please input a word: ";
		std::cin >> input;
		
		//prints lowercase
		for (auto i = 0; i <= input.size(); i++)
		{
			if (input[i] >= 'a' && input[i] <= 'z')
				std::cout << input[i];
		}
		std::cout << std::endl;

		//prints uppercase
		for (auto i = 0; i <= input.size(); i++)
		{
			if (input[i] >= 'A' && input[i] <= 'Z')
				std::cout << input[i];
		}
		std::cout << std::endl;

		//prints symbols
		for (auto i = 0; i <= input.size(); i++)
		{
			if (input[i] < 'A'  || (input[i] > 'Z' && input[i] < 'a') || input[i] > 'z')
				std::cout << input[i];
		}
		std::cout << std::endl;
	}


	return 0;
}