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
	if (argc != 4)
	{
		std::cout << "Bad arguments. Using default.\n";
		columns = 40;
		rows = 20;
		rule = 30;
	}
	else
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
	}

	std::vector<int> row(columns);
	row[row.size() / 2] = 1;
	std::vector<int> rowN(columns);
	std::ofstream fout("text30.txt");
	for (auto n : row)
	{
		fout << n << " ";
	}
	fout << std::endl;

	for (int j = 0; j < rows; j++)
	{
		for (size_t i = 0; i < row.size(); i++)
		{
			if (i == 0)
			{
				if (row[i] || row[i + 1])
				{
					rowN[i] = 1;
				}
			}
			else if (i == row.size() - 1)
			{
				if ((row[i - 1] || row[i]) && (row[i - 1] != row[i]))
				{
					rowN[i] = 1;
				}
			}
			else
			{
				if ((row[i - 1] || (row[i] || row[i + 1])) && (row[i - 1] != (row[i] || row[i + 1])))
				{
					rowN[i] = 1;
				}
			}
		}

		for (auto n : rowN)
		{
			fout << n << " ";
		}
		fout << std::endl;

		row = rowN;
		rowN.assign(columns, 0);
	}

	Image3 image(columns, rows);
	image.loadPPM("text30.txt");
	image.savePPM("image30.PPM");
}