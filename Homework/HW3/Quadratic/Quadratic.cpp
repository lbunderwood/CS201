/*
Luke Underwood
9/23/2019
Quadratic.cpp
Takes a,b,c and outputs roots of the quadratic equation
*/

#include<iostream>
#include<string>
#include<cmath>

float collectInput(std::string message)
{
	float i;
	std::cout << message;
	std::cin >> i;
	return i;
}

int main()
{
	float rootminus = 0;
	float rootplus = 0;
	float a = collectInput("Please enter the coefficient of x^2: ");
	float b = collectInput("Please enter the coefficient of x: ");
	float c = collectInput("Please enter the constant: ");
	float radical = pow(b, 2) - 4 * a * c;

	if (radical >= 0)
	{
		rootminus = (-b - sqrt(radical)) / (2 * a);
		rootplus = (-b + sqrt(radical)) / (2 * a);

		std::cout << "Your roots are: " << rootminus << ", " << rootplus;
	}
	else
	{
		std::cout << "There are no real roots.";
	}

	return 0;
}