/*
Luke Underwood
9/23/2019
Quadratic.cpp
Takes a,b,c and outputs roots of the quadratic equation
*/

#include<iostream>
#include<string>
#include<cmath>
#include<sstream>

//Prints a prompt, then returns the input
bool collectInput(std::string message, float x)
{
	std::cout << message;
	std::string line;
	std::getline(std::cin, line);
	std::istringstream instream(line);
	instream >> x;

	if (instream) return true;
	else return false;
}

int main()
{
	//initialize some variables
	float rootminus = 0;
	float rootplus = 0;

	//collect input
	float a = 0;
	collectInput("Please enter the coefficient of x^2: ", a);
	float b = 0;
	collectInput("Please enter the coefficient of x: ", b);
	float c = 0;
	collectInput("Please enter the constant: ", c);

	//having the contents of the square root predefined is just useful
	float radical = pow(b, 2) - 4 * a * c;

	//checks if solutions are real
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