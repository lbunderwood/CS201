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
void analyzeTokens(const std::vector<std::string>& tokens, 
	std::vector<double>& numbers, std::vector<std::string>& operators)
{
	for (auto n : tokens)
	{
		//Checks if the string is an integer literal
		if (n[0] == '.' || (n[0] >= '0' && n[0] <= '9'))
		{
			for (unsigned int i = 0; i < n.size(); i++)
			{
				if (!(n[i] == '.' || (n[i] >= '0' && n[i] <= '9')))
				{
					std::cout << "[Unidentified]\t\t\"" << n << "\"\n";
					break;
				}
				else if (i == n.size() - 1)
				{
					std::cout << "[Number]\t\t\"" << n << "\"\n";
					std::istringstream instream(n);
					double num;
					instream >> num;
					numbers.push_back(num);
				}
			}
		}
		else if (n == "+" || n == "-" || n == "/" || n == "*" || n == "^")
		{
			std::cout << "[Operator]\t\t\"" << n << "\"\n";
			operators.push_back(n);
		}
		else
		{
			std::cout << "[Unidentified]\t\t\"" << n << "\"\n";
		}
	}
}

void performOperation(std::vector<double>& numbers, 
	std::vector<std::string>& operators)
{
	double calculated = 0;
	if (operators.back() == "+")
	{
		calculated = numbers[numbers.size() - 2] + numbers.back();
	}
	else if (operators.back() == "-")
	{
		calculated = numbers[numbers.size() - 2] - numbers.back();
	}
	else if (operators.back() == "*")
	{
		calculated = numbers[numbers.size() - 2] * numbers.back();
	}
	else if (operators.back() == "/")
	{
		calculated = numbers[numbers.size() - 2] / numbers.back();
	}
	else if (operators.back() == "^")
	{
		calculated = pow(numbers[numbers.size() - 2], numbers.back());
	}
	numbers.pop_back();
	numbers.back() = calculated;
	operators.pop_back();
}

void printVectors(std::vector<double> numbers,
	std::vector<std::string> operators)
{
	for (auto n : numbers)
	{
		std::cout << n << " ";
	}
	for (auto n : operators)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;
}