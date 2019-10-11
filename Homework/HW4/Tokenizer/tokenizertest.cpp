/*
Luke Underwood
10/11/19
tokenizertest.cpp
Contains main function for tokenizer hw assignment
*/

#include"tokenizer.h"

bool readLine(std::string& str)
{
	std::getline(std::cin, str);
	if (str.empty())
		return false;
	else
		return true;
}