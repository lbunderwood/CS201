#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

//takes the input from the user
void inputNames(std::vector<std::string>& names)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		std::string name;
		std::cout << "Please enter name " << i;
		std::getline(std::cin, name);
		names.push_back(name);
	}
}

//searches the names
void searchNames()
{

}

//prints the names
void printNames(std::vector<std::string>& names)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		std::cout << names[i];
	}
}

//sorts the names alphabetically
void sortNames()
{

}