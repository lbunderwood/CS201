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

	std::cout << "Please enter some text. Type end on its own line,"
		<< " then hit enter to end." << std::endl;

	while (str != "end" && str != "End" && str != "END")
	{
		if (readLine(str) && (str != "end" && str != "End" && str != "END"))
		{
			stringToTokens(tokens, str);
			tokens.push_back("");
		}
		else if (str == "end" || str == "End" || str == "END")
		{
			stringToTokens(tokens, str);
		}
		else
		{
			tokens.push_back("");
		}
	}

	analyzeTokens(tokens);
}