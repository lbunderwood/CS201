// Luke Underwood
// 11/27/19
// rule30Main.cpp
// Rule 30 project
// CS201

// Adapted to use all rules using class Rule
// 12/5/19
// By Luke Underwood


#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "Image3.hpp"

int main(int argc, char** argv)
{
	int columns = 0;
	int rows = 0;
	int rule = 0;
	if (argc == 4)
	{
		for (size_t i = 0; i < strlen(argv[1]); i++)
		{
			columns *= 10;
			columns += argv[1][i] - 48;
		}

		for (size_t i = 0; i < strlen(argv[2]); i++)
		{
			rows *= 10;
			rows += argv[2][i] - 48;
		}

		for (size_t i = 0; i < strlen(argv[3]); i++)
		{
			rule *= 10;
			rule += argv[3][i] - 48;
		}

		if (columns < 0)
		{
			std::cout << "Bad columns argument. Using default";
			columns = 40;
		}

		if (rows < 0)
		{
			std::cout << "Bad rows argument. Using default";
			rows = 20;
		}

		if (rule < 0 || rule > 255)
		{
			std::cout << "Bad rule argument. Using default";
			rule = 30;
		}
	}
	else
	{
		std::cout << "Bad arguments. Use <columns>, <rows>, <rule>\n"
			<< "Using defaults";
		columns = 40;
		rows = 20;
		rule = 30;
	}

	Rule rule(columns, rows, rule);
	rule.writeFile("automata.txt");

	Image3 image(columns, rows);
	image.loadPPM("automata.txt");
	image.savePPM("image.PPM");
}