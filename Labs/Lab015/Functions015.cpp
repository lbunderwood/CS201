/*
Luke Underwood
10/7/19
Functions015.cpp
Contains functions for lab 15
*/

#include"Header015.h"

void numSquared(std::vector<std::string>& input)
{
	for (auto & n : input)
	{
		float num;
		std::istringstream instream(n);
		instream >> num;
		num = pow(num, 2);

		if (!instream)
		{
			std::cout << "There is no integer!\n";
		}
		else
		{
			std::cout << num << std::endl;
		}
	}
}