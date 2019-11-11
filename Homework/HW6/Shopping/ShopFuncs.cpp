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
	int quantityMoved;

	//Had this great idea of throwing in a "direction" variable so that this
	//message makes sense and the same function can be used for cart to shop
	//and shop to cart. It is either add or remove
	std::cout << "How many would you like to " << direction << "?" << std::endl;

	//if the input is good...
	if (getInt(quantityMoved))
	{
		//...and if the quantity being moved does no exceed the total quantity
		if (quantityMoved <= from[item].quantity)
		{
			//pull one that number of items out of one thing and into the other
			from[item].quantity -= quantityMoved;
			to[item].quantity += quantityMoved;
		}
		else
		{
			std::cout << "There are not that many " << item << std::endl;
		}
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
	//again I used the "direction" variable so my messages make sense
	//and I avoid massive ammounts of repeated code
	std::cout << "Which item would you like to " << direction << "?\n"
		<< "[Enter one of the numbers below to perform an action]\n";

	//Prints out lines of the menu
	int i = 1;
	for (auto n : from)
	{
		std::cout << "\t" << i << ". " << n.first << std::endl;
		i++;
	}

	//set up some variables for the menu
	int menuchoice;
	int quantity;

	//if the input is good, call moveItem with the appropriate item
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
