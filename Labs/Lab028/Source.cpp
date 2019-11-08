// Luke Underwood
// 11/8/29
// Source.cpp
// Lab028
// CS 201

#include<iostream>
#include<fstream>
#include<iomanip>

int main()
{
	std::ofstream fout("Hello.txt");
	if (!fout)
	{
		std::cout << "ERROR OPENING FILE" << std::endl;
	}
	else
	{
		for(int i = 0; i < 10; i++)
		fout << "Hello World!\n";

		int num = 1;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				fout << std::setw(4) << num;
				num++;
			}
			fout << std::endl;
		}
	}
}