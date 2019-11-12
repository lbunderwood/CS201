/*
Luke Underwood
10/11/19
Tokenizer.cpp
Contains main function for tokenizer hw assignment
*/
// Updated 11/11/19
// Luke Underwood
// For Postfix Calculator project
// renamed PostMain.cpp
// CS201

#include"PostHead.h"

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