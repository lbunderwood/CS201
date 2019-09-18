/*
Luke Underwood
9/18/19
Lab007.cpp
Uses functions in other files to collect data and print them
*/

#include<iostream>
#include<vector>
#include"intio.hpp"

int main()
{
	int i = 0;
	std::vector<int> num;

	for (i = 0; i < 3; i++)
	{
		std::cout << "Please input an integer.\n";
		num.push_back(getInt());
	}

	for (i = 0; i < 3; i++) 
	{
		putInt(num[i], 10);
		std::cout << std::endl;
	}
	
	return 0;
}