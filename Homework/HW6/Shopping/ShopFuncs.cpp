// Luke Underwood
// 11/9/19
// ShopFuncs.cpp
// Shopping
// Homework 6
// CS201
// Contains functions for Shopping program

#include "ShopHead.h"

void printItems(std::map<std::string, item> list)
{
	for (auto n : list)
	{
		std::cout << n.first << ":\n"
			<< "\t" << n.second.description << "\n"
			<< "\t" << n.second.price << " gold pieces\n"
			<< "\tQuantity: " << n.second.quantity << std::endl;
	}
}

bool getInt(int& num)
{
	std::string input;

	getline(std::cin, input);
	std::istringstream instream(input);
	instream >> num;

	if (instream)
		return true;
	else
		return false;
}

void addToCart(std::map<std::string, item>& from, std::map<std::string, item>& to)
{
	std::cout << "Which item would you like to add to your cart?\n"
		<< "[Enter one of the numbers below to perform an action]\n";
	int i = 1;
	for (auto n : from)
	{
		std::cout << "\t" << i << ". " << n.first << std::endl;
	}

	int menuchoice;
	std::string menustring;
	std::getline(std::cin, menustring);
	std::istringstream instream(menustring);
	instream >> menuchoice;

	if (instream)
	{
		switch (menuchoice)
		{
		case 1:
			printItems(store);
			break;
		case 2:
		case 3:
		case 4:
			printItems(cart);
			break;
		case 5:
		default:
			std::cout << "Please enter a number 1-5" << std::endl;
		}
	}
	else
	{
		std::cout << "Please enter an integer" << std::endl;
	}
}
