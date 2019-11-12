// Luke Underwood
// 11/9/19
// RandoFunc.cpp
// RandoMap
// Homework 6
// CS201
// Contains functions for RandoMap project

#include "RandoHead.h"

//Uniform Distrib
int randomBetweenU(int first, int last, std::mt19937& e2)
{
	std::uniform_int_distribution<> uniform_dist(first, last);

	return (int)std::round(uniform_dist(e2));
}

//Normal Distrib
int randomBetweenN(int mean, int radius, std::mt19937& e2)
{
	std::normal_distribution<> normal_dist(mean, 4);
	int num = (int)std::round(normal_dist(e2));
	if (num > mean + radius)
		return mean + radius;
	else if (num < mean - radius)
		return mean - radius;
	else
		return num;
}

//Using rand()
int randomBetween(int first, int last)
{
	int range = last - first + 1;
	return (rand() % range) + first;
}

//Print map
void printDistrib(const std::map<int, int>& numbers)
{
	for (auto p : numbers) {
		std::cout << std::fixed << std::setprecision(1) << std::setw(3)
			<< p.first << ' ' << std::string(p.second / 200, '*') << '\n';
	}
}