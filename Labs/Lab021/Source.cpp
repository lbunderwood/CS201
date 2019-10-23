//Luke Underwood
//10/23/19
//CS201

#include"truncstruct.hpp"
#include<iostream>

int main()
{
	StringInfo foo;
	getline(std::cin, foo.str);
	std::cin >> foo.len;
	std::cout << trunc(foo).str;
}