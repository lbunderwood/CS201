/*
Luke Underwood
10/11/19
Tokenizer.cpp
Contains main function for tokenizer hw assignment
*/

#include"tokenizer.h"

int main()
{
	std::string str;
	std::vector<std::string> tokens;

	if (readLine(str))
	{
		stringToTokens(tokens, str);
		analyzeTokens(tokens);
	}
	else
	{
		std::cout << "Please try again.";
	}
}