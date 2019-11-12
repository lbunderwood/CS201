/*
Luke Underwood
10/11/19
tokenizertest.cpp
Contains main function for tokenizer hw assignment
*/
// Updated 11/11/19
// Luke Underwood
// For Postfix Calculator project
// renamed PostFuncs.cpp
// CS201

#include"PostHead.h"


//collects a input from the user as one long string.
//returns string by reference.
//returns true if there is a string, false if not.
bool readLine(std::string& line)
{
	std::getline(std::cin, line);
	
	if (line.empty())
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

	return tokens.size();
}


//Classifies each token, then prints it along with its classification
//returns void
void analyzeTokens(const std::vector<std::string>& tokens)
{
	for (auto n : tokens)
	{
		//Checks if the string is an integer literal
		if (n[0] >= '0' && n[0] <= '9')
		{
			for (unsigned int i = 0; i < n.size(); i++)
			{
				if ((n[i] >= '!' && n[i] <= '/') || (n[i] >= ':' && n[i] <= '@')
					|| (n[i] >= '[' && n[i] <= '`') || (n[i] >= '{' && n[i] <= '~'))
				{
					std::cout << "[special]\t\t\"" << n << "\"\n";
					break;
				}
				else if (!(n[i] >= '0' && n[i] <= '9'))
				{
					std::cout << "[unidentified]\t\t\"" << n << "\"\n";
					break;
				}
				else if (i == n.size() - 1)
				{
					std::cout << "[integer]\t\t\"" << n << "\"\n";
				}
			}
		}

		//Checks if the string is an identifier literal
		if ((n[0] >= 'a' && n[0] <= 'z') || (n[0] >= 'A' && n[0] <= 'Z')
			|| n[0] == '_')
		{
			for (unsigned int i = 0; i < n.size(); i++)
			{
				if ((n[i] >= '!' && n[i] <= '/') || (n[i] >= ':' && n[i] <= '@')
					|| (n[i] >= '[' && n[i] <= '`') || (n[i] >= '{' && n[i] <= '~'))
				{
					std::cout << "[special]\t\t\"" << n << "\"\n";
					break;
				}
				else if (i == n.size() - 1)
				{
					std::cout << "[identifier]\t\t\"" << n << "\"\n";
				}
			}
		}

		//Checks if the string is a whitespace literal
		if (n[0] >= 0 && n[0] <= 32)
		{
			std::cout << "[whitespace]\t\t\"" << n << "\"\n";
			continue;
		}

		//Checks if the string is a string literal
		if (n[0] == '"' && n[n.size()-1] == '"')
		{
			std::cout << "[string]\t\t\"" << n << "\"\n";
			continue;
		}

		//Checks if the string has special characters
		if ((n[0] >= '!' && n[0] <= '/') || (n[0] >= ':' && n[0] <= '@') 
			|| (n[0] >= '[' && n[0] <= '`') || (n[0] >= '{' && n[0] <= '~'))
		{
			std::cout << "[special]\t\t\"" << n << "\"\n";
		}
	}
}