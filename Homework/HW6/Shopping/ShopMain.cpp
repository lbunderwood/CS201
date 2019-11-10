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
	for (auto n : store)
	{
		n.second.quantity = (int)std::round(normal_dist(e2));
	}

	//Now all of our data is set up, time to print out an interface
	int menuchoice = 0;

	while (menuchoice != /*EDIT ME*/)
	{

	}
	
}