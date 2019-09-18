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
	int j = 0;
	std::vector<int> num;
	int totalnum = 0;

	while (true)
	{
		std::cout << "Please input an integer.\n";
		num.push_back(getInt());
		if (num[i] == 0)
		{
			break;
		}
			
		i++;
	}

	for (j = 0; j <= i; j++) 
	{
		totalnum = totalnum + num[j];
	}

	putInt(totalnum, 10);
	
	return 0;
}