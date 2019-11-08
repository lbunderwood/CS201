// Luke Underwood
// 11/6/19
// Source.cpp
// CS201
// Lab 27

#include<iostream>
#include<random>

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(0, 1);
	int heads = 0;
	int tails = 0;

	for (int i = 0; i < 100; i++)
	{
		if (distrib(gen) == 1)
		{
			std::cout << "Heads" << std::endl;
			heads++;
		}
		else
		{
			std::cout << "Tails" << std::endl;
			tails++;
		}
	}

	std::cout << "Total Heads: " << heads << std::endl;
	std::cout << "Total Tails: " << tails;

}