// Luke Underwood
// 12/4/19
// agent.h
// Thermostat project
// CS201

#ifndef SIMULATOR_H
#define SIMULATOR_H
#include<utility>

class Agent
{
public:

	//Default Constructor
	Agent();

	//Constructor with bounds (double lower, double upper)
	Agent(double lower, double upper);

private:
	std::pair<double, double> bounds_;
};

#endif