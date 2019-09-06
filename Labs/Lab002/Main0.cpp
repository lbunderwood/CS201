/*
Luke Underwood
9/4/2019
Prints a date given three inputs
*/

#include <iostream>

int main()
{
	int day;
	int month;
	int year;
	std::cout << "Please input the day of the month you were born" << std::endl;
	std::cin >> day;
	std::cout << "Please input the month you were born" << std::endl;
	std::cin >> month;
	std::cout << "Please input the year you were born" << std::endl;
	std::cin >> year;
	std::cout << month << "/" << day << "/" << year << std::endl;
	std::cout << year << "-" << month << "-" << day << std::endl;
	return 0;
}