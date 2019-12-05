// Luke Underwood
// 12/4/19
// simulator.cpp
// Thermostat project
// CS201

#include "simulator.h"
#include<iostream>
#include<string>
#include<sstream>

Simulator::Simulator() {};

bool Simulator::askOwner()
{
	for (int i = 0; i < 10; i++)
	{
		environment.iteration();
		agent.act(environment);
		std::cout << "Current temp: " << environment.getTemperature() << " C"
			<< std::endl;
	}

	std::cout << "Would you like to change the bounds?" << std::endl
		<< "Enter Y or N (or enter E to end simulation): ";

	std::string line;
	std::getline(std::cin, line);

	if (line[0] == 'Y' || line[0] == 'y')
	{
		double lower;
		std::cout << "Enter new lower bound: ";
		
		while (!getDouble(lower))
		{
			std::cout << "Please enter a value." << std::endl;
		}

		double upper;
		std::cout << "Enter new upper bound: ";

		while (!getDouble(upper))
		{
			std::cout << "Please enter a value." << std::endl;
		}

		agent.setBounds(lower, upper);
	}
	else if (line[0] == 'E' || line[0] == 'e')
	{
		return false;
	}

	return true;
}


bool getDouble(double& input)
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream instream(line);
	instream >> input;
	return (bool)instream;
}