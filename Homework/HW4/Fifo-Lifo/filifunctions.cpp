// Luke Underwood
// 10/15/19
// filifunctions.cpp
// Functions for Fifo-Lifo project (see fifo-lifo.cpp for details)

#include"Header.h"


void fifoPush(std::vector<std::string>& container, const std::string& item)
{
	container.emplace(container.begin(),item);
	std::cout << item << " has been added." << std::endl;
}


void lifoPush(std::vector<std::string>& container, const std::string& item)
{
	container.push_back(item);
	std::cout << item << " has been added." << std::endl;
}



void fifoPop(std::vector<std::string>& container)
{
	if (isContainerEmpty(container))
	{
		std::cout << "There is nothing to remove." << std::endl;
	}
	else
	{
		std::cout << container[0] << " has been removed." << std::endl;
		container.erase(container.begin());
	}
}


void lifoPop(std::vector<std::string>& container)
{
	if (isContainerEmpty(container))
	{
		std::cout << "There is nothing to remove." << std::endl;
	}
	else
	{
		std::cout << container[container.size()-1] << " has been removed." << std::endl;
		container.pop_back();
	}
}



bool isContainerEmpty(const std::vector<std::string>& container)
{
	if (container.size())
		return false;
	else
		return true;
}


void printContainer(const std::vector<std::string>& container)
{
	for (auto n : container)
		std::cout << n << std::endl;
}



bool fifoTest()
{
	int counter = 0;
	std::vector<std::string> test = { "0" };

	fifoPush(test, "Hello World");
	if (test[0] == "Hello World")
		counter++;

	fifoPop(test);
	if (test[0] == "0")
		counter++;

	if (counter == 2)
		return true;
}


bool lifoTest()
{
	int counter = 0;
	std::vector<std::string> test = { "0" };

	lifoPush(test, "Hello World");
	if (test[1] == "Hello World")
		counter++;

	lifoPop(test);
	if (test[0] == "0" && test.size() == 1)
		counter++;

	if (counter == 2)
		return true;
}