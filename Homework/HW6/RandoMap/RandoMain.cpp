// Luke Underwood
// 11/9/19
// RandoMain.cpp
// RandoMap
// Homework 6
// CS201
// Contains main program for RandoMap project

#include "RandoHead.h"

int main()
{
	std::random_device r;
	// Choose a random mean between 1 and 6
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 6);
	int mean = uniform_dist(e1);
	int radius = 12;
	std::cout << "Randomly-chosen mean: " << mean << '\n'
		<< "Radius: " << radius << std::endl;
	
	// Generate a normally distributed number around the mean
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 e2(seed2);

	std::map<int, int> normal;
	for (size_t i = 0; i < 100000; i++)
	{
		++normal[randomBetweenN(mean, radius, e2)];
	}
	std::cout << "Normal distribution around " << mean << ":\n";
	printDistrib(normal);

	int first = mean - radius;
	int last = mean + radius;
	std::map<int, int> uniform;
	for (size_t i = 0; i < 100000; i++)
	{
		++uniform[randomBetweenU(first, last, e2)];
	}
	std::cout << "Uniform distribution between " << first << " and " << last << ":\n";
	printDistrib(uniform);

	std::map<int, int> rand;
	for (size_t i = 0; i < 100000; i++)
	{
		++rand[randomBetween(first, last)];
	}
	std::cout << "Random distribution between " << first << " and " << last << ":\n";
	printDistrib(rand);
}