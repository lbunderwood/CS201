/*
Luke Underwood
9/5/2019
mileskm
Converts miles to kilometers
*/

#include <iostream>
#include <iomanip>

int main()
{
	//let's set up some variables
	float miles;
	float km;

	//collect input
	std::cout << "Please enter the number of miles\n";
	std::cin >> miles;

	//calculate output
	km = miles * 1.609;

	//set decimals to 5
	std::cout << std::setprecision(5);

	//give output
	std::cout << miles << " miles = " << km << " kilometers";

	return 0;
}