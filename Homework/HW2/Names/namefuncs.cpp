#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"nameheader.h"

//takes the input from the user
void inputNames(std::vector<std::string> & names)
{
	int i = 0;
	names.clear();
	for (i = 0; i < 10; i++)
	{
		std::string name;
		std::cout << "Please enter name " << i+1 << std::endl;
		std::cin >> name;
		names.push_back(name);
	}
}

//searches the names
bool searchNames(std::vector<std::string>& names, std::string search)
{
	int i = 0;
	bool exists = false;
	for (i = 0; i < 10; i++)
	{
		if (names[i] == search)
		{
			exists = true;
		}
	}
	return exists;
}

//prints the names
void printNames(std::vector<std::string> & names)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		std::cout << names[i] << std::endl;
	}
}

//sorts the names alphabetically
void sortNames(std::vector<std::string>& names)
{

}