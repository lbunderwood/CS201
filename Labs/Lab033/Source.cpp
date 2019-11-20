// Luke Underwood
// CS 201
// 11/20/19
// Lab 33
// Source.cpp  bad name, I know

#include<iostream>
#include<string>
#include<sstream>

class Pancakes {
public:

	void setPancakes(std::string message) 
	{
		std::cout << "How many pancakes " << message << " have?\n";
		std::getline(std::cin, pancakestr_);
		std::istringstream instream(pancakestr_);
		instream >> pancakenum_;
		while (!instream)
		{
			std::cout << "Try Again\n";
			std::getline(std::cin, pancakestr_);
			std::istringstream instream(pancakestr_);
			instream >> pancakenum_;
		}
	}

	int getPancakes()
	{
		return pancakenum_;
	}

private:
	std::string pancakestr_;
	int pancakenum_ = 0;
};


int main()
{
	Pancakes yours;
	yours.setPancakes("do you");
	std::cout << "You have " << std::to_string(yours.getPancakes()) << " pancakes.\n";

	Pancakes friends;
	friends.setPancakes("does your friend");
	std::cout << "Your friend has " << std::to_string(friends.getPancakes()) << " pancakes.\n";
	return 0;
}