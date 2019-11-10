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

void moveItem(
	std::map<std::string, item>& from, std::map<std::string, item>& to, 
	std::string item, std::string direction)
{
	int quantity;
	std::cout << "How many would you like to " << direction << "?" << std::endl;
	if (getInt(quantity))
	{
		from[item].quantity -= quantity;
		to[item].quantity += quantity;
	}
	else
	{
		std::cout << "Please enter a valid input";
	}
}

void moveMenu(
	std::map<std::string, item>& from, std::map<std::string, item>& to, 
	std::string direction)
{
	std::cout << "Which item would you like to " << direction << "?\n"
		<< "[Enter one of the numbers below to perform an action]\n";
	int i = 1;
	for (auto n : from)
	{
		std::cout << "\t" << i << ". " << n.first << std::endl;
		i++;
	}

	int menuchoice;
	int quantity;

	if (getInt(menuchoice))
	{
		switch (menuchoice)
		{
		case 1:
			moveItem(from, to, "Health Potions", direction);
			break;
		case 2:
			moveItem(from, to, "Magica Potions", direction);
			break;
		case 3:
			moveItem(from, to, "Shields", direction);
			break;
		case 4:
			moveItem(from, to, "Spellbooks", direction);
			break;
		case 5:
			moveItem(from, to, "Swords", direction);
			break;
		default:
			std::cout << "Please enter a number 1-5" << std::endl;
		}
	}
	else
	{
		std::cout << "Please enter an integer" << std::endl;
	}
}
