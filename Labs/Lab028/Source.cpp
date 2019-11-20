// Luke Underwood
// 11/8/29
// Source.cpp
// Lab028
// CS 201

#include<iostream>
#include<fstream>
#include<iomanip>
#include<random>
#include<vector>
#include<algorithm>
#include<chrono>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distrib(0, 999);

void printIntegersToFile(std::vector<int>& integers, std::ofstream& output)
{
	shuffle(integers.begin(), integers.end(), gen);

	int num = 0;
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			output << std::setw(4) << integers[num];
			num++;
		}
		output << std::endl;
	}
}


int main()
{
	std::vector<int> integers;

	std::ofstream fout("Hello.txt");

	if (!fout)
	{
		std::cout << "ERROR OPENING FILE" << std::endl;
	}
	else
	{
		fout << "PART 1: " << std::endl;
		for(int i = 0; i < 10; i++)
		fout << "Hello World!\n";

		fout << "PART 2: " << std::endl;
		int num = 1;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				fout << std::setw(4) << num;
				integers.push_back(num);
				num++;
			}
			fout << std::endl;
		}

		fout << std::endl;

		fout << "A PART THAT I MADE UP: " << std::endl;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				fout << std::setw(4) << distrib(gen);
			}
			fout << std::endl;
		}

		fout << std::endl;

		fout << "ADDITIONAL 1: " << std::endl;
		printIntegersToFile(integers, fout);
	}
}