// Luke Underwood
// 12/5/19
// Rule.cpp
// source file for Rule class for rule 30 update for HW8
// CS201


#include "Rule.h"


Rule::Rule() : rows_(20), columns_(40), ruleNum_(30) {}

Rule::Rule(int rows, int columns, int ruleNum) : rows_(rows), columns_(columns), ruleNum_(ruleNum) {}

std::vector<std::vector<int>> Rule::createVector()
{
	//vector to hold automata as array of 1's and 0's
	std::vector<std::vector<int>> ruleVec;

	//vector to hold each row as it is generated
	std::vector<int> row(columns_);

	//create initial row and add to ruleVec
	row[row.size() / 2] = 1;
	ruleVec.push_back(row);

	//cycle through rows
	for (int i = 0; i < rows_; i++)
	{
		//reset row
		row.assign(columns_, 0);

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
				row[j] = 1;
			}
		}

		//add row to array
		ruleVec.push_back(row);
	}

	return ruleVec;
}