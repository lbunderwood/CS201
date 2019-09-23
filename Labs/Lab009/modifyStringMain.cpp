/*
Luke Underwood
9/23/19
Lab009.cpp

*/

#include<iostream>
#include<string>
#include"modifyString.h"

int main()
{
	std::string inputstring;
	int n;

	std::cout << "Please enter a string: ";
	std::cin >> inputstring;

	std::cout << "Please enter an integer: ";
	std::cin >> n;

	std::cout << "The length of your string is now: "
		<< modifyString(inputstring, n) << std::endl 
		<< "You string is now: " << inputstring;


	return 0;
}