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
	return true;
}


bool lifoTest()
{
	return true;
}