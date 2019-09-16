#include<iostream>
#include<vector>;
#include<string>;
#include<algorithm>;

//takes the input from the user
void inputNames(std::vector<std::string> & names)
{
	int i = 0;
	std::vector<std::string> names;
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
void printNames()
{
	
}

//sorts the names alphabetically
void sortNames()
{

}