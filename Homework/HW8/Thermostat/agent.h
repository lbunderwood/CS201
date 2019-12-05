// Luke Underwood
// 12/4/19
// agent.h
// Thermostat project
// CS201

#ifndef AGENT_H
#define AGENT_H
#include<utility>
#include"environment.h"

class Agent
{
public:

	//Default Constructor
	Agent();

	//Constructor with bounds (double lower, double upper)
	Agent(double lower, double upper);

	//Checks current temperature
	std::pair<double, bool> percieve(Environment environment);

	//Returns true if heater should be changed
	bool think(Environment environment);

	//acts on environment if neccessary
	void act(Environment& environment);

	//sets new bounds
	void setBounds(double lower, double upper);

	//gets bounds
	std::pair<double, double> getBounds();

private:

	//holds lower, upper bounds set by user
	std::pair<double, double> bounds_;
};

#endif