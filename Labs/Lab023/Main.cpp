//Luke Underwood
//10/28/19
//CS201
//Main.cpp
//contains main function for lab 23

#include<iostream>
#include<map>

int main()
{
	std::map<std::string, int> M1
	{
		{"Dog", 10},
		{"Cat", 7},
		{"Fish", 3},
		{"Bird", 5},
		{"Lizard", 6},
	};

	M1.erase("Bird");

	for (auto n : M1)
	{
		std::cout << n.first << " " << n.second << std::endl;
	}


}