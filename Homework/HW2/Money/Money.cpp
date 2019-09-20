/*
Luke Underwood
9/19/2019
Money.cpp
Allows the user to input numbers of coins, then tells them the ammount of
money that they have in total
*/

#include<iostream>
#include<iomanip>

int main()
{
	//initialize variables
	int penny = 0;
	int nickle = 0;
	int dime = 0;
	int quarter = 0;
	int half = 0;
	int dollarcoin = 0;
	float cents = 0;
	float dollars = 0;
	int digits = 0;
	int dollarsdigits = 0;

	//collect input
	std::cout << "How many pennies do you have?\n";
	std::cin >> penny;
	std::cout << "How many nickles do you have?\n";
	std::cin >> nickle;
	std::cout << "How many dimes do you have?\n";
	std::cin >> dime;
	std::cout << "How many quarters do you have?\n";
	std::cin >> quarter;
	std::cout << "How many half dollars do you have?\n";
	std::cin >> half;
	std::cout << "How many dollar coins do you have?\n";
	std::cin >> dollarcoin;

	//calculate total monies
	cents = penny + nickle * 5 + dime * 10 + quarter * 25 +
		half * 50 + dollarcoin * 100;
	dollars = cents / 100;

	//print coin ammounts
	std::cout << "You have " << penny;
	if (penny == 1)
	{
		std::cout << " penny,\n";
	} else {
		std::cout << " pennies,\n";
	}
	std::cout << nickle;
	if (nickle == 1)
	{
		std::cout << " nickle,\n";
	}
	else {
		std::cout << " nickles,\n";
	}
	std::cout << dime;
	if (dime == 1)
	{
		std::cout << " dime,\n";
	}
	else {
		std::cout << " dimes,\n";
	}
	std::cout << quarter;
	if (quarter == 1)
	{
		std::cout << " quarter,\n";
	}
	else {
		std::cout << " quarters,\n";
	}
	std::cout << half;
	if (half == 1)
	{
		std::cout << " half dollar,\n";
	}
	else {
		std::cout << " half dollars,\n";
	}
	std::cout << dollarcoin;
	if (dollarcoin == 1)
	{
		std::cout << " dollar coin,\n";
	}
	else {
		std::cout << " dollar coins,\n";
	}
	//feels bad hard coding all of this but I'm unsure how make this
	//work as a function :/

	//print total monies
	std::cout << "You have " << cents << " cents, which is $" << std::fixed 
		<< std::setprecision(2) << dollars;

	return 0;
}