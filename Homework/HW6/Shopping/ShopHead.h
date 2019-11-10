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
#include<algorithm>
#include<string>
#include<map>
#include<random>
#include<iomanip>
#include<vector>
#include<sstream>

//Structs
struct item
{
	int quantity = 0;
	double price;
	std::string description;
};

//functions
void printItems(std::map<std::string, item> list);


#endif
