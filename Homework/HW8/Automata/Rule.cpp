// Luke Underwood
// 12/5/19
// Rule.cpp
// source file for Rule class for rule 30 update for HW8
// CS201


#include "Rule.h"
#include<fstream>
#include<iostream>

Rule::Rule() : columns_(40), rows_(20), ruleNum_(30) {}

Rule::Rule(int columns, int rows, int ruleNum) : 
	columns_(columns), rows_(rows), ruleNum_(ruleNum) {}

//creates an array of the automata
std::vector<std::vector<int>> Rule::createVector()
{
	//vector to hold automata as array of 1's and 0's
	std::vector<std::vector<int>> ruleVec;

	//vector to hold each row as it is generated
	std::vector<int> row;

	//create initial row and add to ruleVec
	for (int i = 0; i < columns_; i++)
	{
		if (i == columns_ / 2)
		{
			row.push_back(1);
		}
		else
		{
			row.push_back(0);
		}
	}
	ruleVec.push_back(row);

	//cycle through rows
	for (int i = 1; i < rows_; i++)
	{
		//reset row
		row.clear();

		//cycle through columns
		for (int j = 0; j < columns_; j++)
		{
			//create "condition," a 3-bit number representing the input
			int condition = 0;
			if (j > 0)
			{
				condition += ruleVec[i - 1][j - 1] * 4;
			}
			condition += ruleVec[i - 1][j] * 2;
			if (j < columns_ - 1)
			{
				condition += ruleVec[i - 1][j + 1];
			}

			//bitwise operation that uses condition and rule to decide output
			if ((int)pow(2, condition) & ruleNum_)
			{
				row.push_back(1);
			}
			else
			{
				row.push_back(0);
			}
		}

		//add row to array
		ruleVec.push_back(row);
	}

	//print confirmation that this step was completed
	std::cout << "Automata constructed" << std::endl;

	//return array
	return ruleVec;
}

void Rule::writeFile(const std::string& path)
{
	std::ofstream fout(path);
	std::vector<std::vector<int>> automata = createVector();

	//cycle through automata, outputting values into file in a nice format
	for (auto n : automata)
	{
		for (auto m : n)
		{
			fout << m << " ";
		}
		fout << std::endl;
	}

	//print confirmation that this step was completed
	std::cout << "Text file written" << std::endl;
}