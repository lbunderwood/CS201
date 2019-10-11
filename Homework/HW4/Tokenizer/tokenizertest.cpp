/*
Luke Underwood
10/11/19
tokenizertest.cpp
Contains main function for tokenizer hw assignment
*/

#include"tokenizer.h"


//collects a input from the user as one long string.
//returns string by reference.
//returns true if there is a string, false if not.
bool readLine(std::string& str)
{
	std::getline(std::cin, str);
	if (str.empty())
		return false;
	else
		return true;
}


//takes a string composed of several tokens and puts the tokens
//separately into a vector, then returns the vector by reference.
//returns the number of tokens
unsigned stringToTokens(std::vector<std::string>& tokens, std::string str)
{
	std::istringstream instream(str);
	std::string a;
	while (instream)
	{
		instream >> a;
		tokens.push_back(a);
	}
	tokens.pop_back();
	tokens.push_back("");

	return tokens.size();
}