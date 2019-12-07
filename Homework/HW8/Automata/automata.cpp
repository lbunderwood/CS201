// Luke Underwood
// 11/27/19
// rule30Main.cpp
// Rule 30 project
// CS201

// Adapted to use all rules using class Rule
// renamed to automata.cpp
// 12/5/19
// By Luke Underwood


#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "Image3.hpp"
#include "Rule.h"

int main(int argc, char** argv)
{
	int columns = 0;
	int rows = 0;
	int rule = 0;
	if (argc == 4)
	{
		columns = std::stoi(argv[1]);
		rows = std::stoi(argv[2]);
		rule = std::stoi(argv[3]);

		if (columns <= 0)
		{
			std::cout << "Bad columns argument. Using default\n";
			columns = 40;
		}

		if (rows <= 0)
		{
			std::cout << "Bad rows argument. Using default\n";
			rows = 20;
		}

		if (rule <= 0 || rule > 255)
		{
			std::cout << "Bad rule argument. Using default\n";
			rule = 30;
		}
	}
	else
	{
		std::cout << "Bad arguments. Use <columns>, <rows>, <rule>\n"
			<< "Using defaults\n";
		columns = 40;
		rows = 20;
		rule = 30;
	}

	Rule automata(columns, rows, rule);
	automata.writeFile("automata.txt");

	Image3 image(columns, rows);
	image.loadPPM("automata.txt");
	image.savePPM("image.PPM");
}