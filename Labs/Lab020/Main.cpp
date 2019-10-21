/*
Luke Underwood
10/21/19
Lab020
Main.cpp
*/
#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<cmath>

int main()
{
	std::cout << "PART 1:" << std::endl;

	int degrees = 0;
	double cosine;

	for (degrees = 0; degrees <= 180; degrees += 5)
	{
		std::cout << std::fixed << std::setw(3) << degrees << ", ";
		cosine = cos(degrees * M_PI / 180);
		std::cout << std::setprecision(8) << std::setw(11) << cosine << std::endl;
	}

	std::cout << std::endl << "PART 2:" << std::endl;
	int x = 0;
	double value;

	for (x = 0; x <= 180; x += 5)
	{
		std::cout << std::scientific << std::setw(3) << x << ", ";
		value = pow(M_E, (x / 10));
		std::cout << std::setprecision(8) << std::setw(11) << value << std::endl;
	}
}