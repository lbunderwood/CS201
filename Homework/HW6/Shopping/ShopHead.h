// Luke Underwood
// 11/9/19
// ShopHead.h
// Shopping
// Homework 6
// CS201
// Contains library inclusions, function prototypes, and struct definitions
// for Shopping program

#ifndef SHOPHEAD_H
#define SHOPHEAD_H

//library inclusions
#include<iostream>
#include<numeric>
#include<string>
#include<map>
#include<random>
#include<iomanip>
#include<vector>
#include<sstream>


//Holds quantity, price, and description of an item
struct item
{
	int quantity = 0;
	double price;
	std::string description;
};


//Functions:

//Prints all of the items either in the cart or shop with all of 
//their information
void printItems(std::map<std::string, item> list);

//returns whether an int was entered, and returns the int by reference
bool getInt(int& num);

//moves an item to or from the cart. pass map the item is coming from, then the
//map it is going to, then the item to be moved, then either "add" or "remove"
//depending on whether it is going to or from the cart
void moveItem(
	std::map<std::string, item>& from, std::map<std::string, item>& to,
	std::string item, std::string direction);

//a menu for moving items to and from the cart. pass the map the item is being
//moved from, then the map it is moving to, then "add" or "remove" depending
//on the context
void moveMenu(
	std::map<std::string, item>& from, std::map<std::string, item>& to,
	std::string direction);

#endif