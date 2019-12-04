// Luke Underwood
// 12/4/19
// agent.h
// Thermostat project
// CS201

#ifndef AGENT_H
#define AGENT_H
#include<utility>

class Agent
{
public:

	//Default Constructor
	Agent();

	//Constructor with bounds (double lower, double upper)
	Agent(double lower, double upper);

private:

	//holds lower, upper bounds set by user
	std::pair<double, double> bounds_;
};

#endif