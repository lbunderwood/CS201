// Luke Underwood
// 11/9/19
// ShopMain.cpp
// Shopping
// Homework 6
// CS201
// Contains main program for Shopping project

#include "ShopHead.h"

int main()
{
	//Initialize items with prices and descriptions. Quantities are 0 by
	//default, so they're already set up for the cart, and it's best to
	//set up the store's quantities later with a for loop
	item sword;
	sword.price = 50;
	sword.description = "Simple but sturdy steel swords.";

	item shield;
	shield.price = 40;
	shield.description = "They aren't pretty but they could save your life.";

	item spellbook;
	spellbook.price = 100;
	spellbook.description = "Ancient tomes to aid the magically adept.";

	item Hpotion;
	Hpotion.price = 15;
	Hpotion.description = "A necessity for tight scrapes in combat.";

	item Mpotion;
	Mpotion.price = 20;
	Mpotion.description = "Replenishes your magica to keep the fireballs coming.";

	//Organize items in a map
	std::map<std::string, item> store =
	{
		{"Health Potions", Hpotion},
		{"Magica Potions", Mpotion},
		{"Swords", sword},
		{"Shields", shield},
		{"Spellbooks", spellbook}
	};

	//They're the same at this point, so we make a copy for the cart
	std::map<std::string, item> cart = store;

	//Set up an RNG to set store quantities
	std::random_device r;
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist(10, 3);

	//Set quantities randomly for store, normally distributed around 10
	for (auto& n : store)
	{
		n.second.quantity = (int)std::round(normal_dist(e2));
	}

	//Now all of our data is set up, time to print out an interface
	int menuchoice = 0;

	//Just a few skyrim and borderlands 2 references to sprinkle in
	std::vector<std::string> messages =
	{
		"Some people call this junk. Me? I call it treasure.\n",
		"A fantastic day for capitalism!\n",
		"Let's just get this out of the way. Yes, most of my "
		"merchandise was ripped from the hands of dead adventurers.\n",
		"Why loot the dead when you can buy from me?\n",
		"Looking to protect yourself? Or deal some damage?\n",
		"You won't find better merchandise anywhere else! "
		"I've made sure of that.\n",
		"High quality, low prices, and no questions asked!\n",
		"Welcome to my humble shop!\n"
	};

	//uniform distribution to select one of the above voicelines
	std::uniform_int_distribution<> uniformDist(0, 7);

	//Main program loop. Prints a message, a menu, and allows the user to perform an action once per iteration
	while (menuchoice != 5)
	{
		
		std::cout << messages[uniformDist(e2)]
			<< "[Enter one of the numbers below to perform an action]\n"
			<< "\t1. View available items\n"
			<< "\t2. Add an item to your cart\n"
			<< "\t3. Remove an item from your cart\n"
			<< "\t4. View your current cart\n"
			<< "\t5. Purchase your items\n"
			<< std::endl;

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
				moveMenu(store, cart, "add");
				break;
			case 3:
				moveMenu(cart, store, "remove");
				break;
			case 4:
				printItems(cart);
				std::cout << "Total Price: " 
					<< std::accumulate(cart.begin(), cart.end(), 0, 
						[](int total, std::pair<std::string, item> current)
						{
							return total + current.second.price * current.second.quantity;
						})
					<< std::endl;
				break;
			case 5:
				std::cout << "You have been charged " 
					<< std::accumulate(cart.begin(), cart.end(), 0,
						[](int total, std::pair<std::string, item> current)
						{
							return total + current.second.price * current.second.quantity;
						})
					<< " gold pieces for ";
				for (auto n : cart)
				{
					if (n.second.quantity != 0)
					{
						std::cout << n.second.quantity << " " << n.first;
						if (n.first != "Swords")
						{
							std::cout << ", ";
						}
					}
				}
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
	
}