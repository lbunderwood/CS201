// Created by Luke Underwood
// 11/27/19
// Main.cpp
// caeser cypher project
// CS201

#include<iostream>
#include<string>
#include<sstream>

void cypherLetter(char& c, const int key, const char lower, const char upper)
{
	if (c >= lower && c <= upper)
	{
		c += key;
		if (c > upper)
		{
			c -= 26;
		}
	}
}

bool getNum(int& num)
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream instream(line);
	instream >> num;
	return (bool)instream;
}

int main()
{
	std::string text;
	int key;

	std::cout << "Enter a blank line at any time to end" << std::endl;
	while (true)
	{
		std::cout << "Please enter the text you would like to cypher: ";
		std::getline(std::cin, text);
		if (text == "")
		{
			break;
		}

		std::cout << "Enter the number of places to shift it: ";
		while(!getNum(key))
		{
			std::cout << "Please enter a NUMBER: ";
		}

		for (auto& n : text)
		{
			cypherLetter(n, key, 'A', 'Z');
			cypherLetter(n, key, 'a', 'z');
		}
		std::cout << std::endl << "Your new word is: " << text << std::endl << std::endl;
	}

	return 0;
}