// Luke Underwood
// 12/4/19
// simulator.h
// Thermostat project
// CS201

#ifndef SIMULATOR_H
#define SIMULATOR_H
#include"agent.h"
#include"environment.h"

class Simulator
{
public:

	//Default Constructor
	Simulator();

	//Gets new bounds and gives option to exit program
	bool askOwner();

	//Runs simulation
	void run();

private:
	Agent agent;
	Environment environment;
};


bool getDouble(double& input);

#endif