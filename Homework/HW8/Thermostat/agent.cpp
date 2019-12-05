// Luke Underwood
// 12/4/19
// agent.cpp
// Thermostat project
// CS201

#include "agent.h"

Agent::Agent() : 
	bounds_(15, 25) {}

Agent::Agent(double lower, double upper) : 
	bounds_(lower, upper) {}

std::pair<double, bool> Agent::percieve(Environment environment)
{
	std::pair<double, bool> status = 
		{ environment.getTemperature(), environment.getHeater() };

	return status;
}

bool Agent::think(Environment environment)
{
	if (percieve(environment).first >= bounds_.second 
		&& percieve(environment).second)
	{
		return true;
	}
	else if (percieve(environment).first <= bounds_.first 
		&& !percieve(environment).second)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Agent::act(Environment environment)
{
	if (think(environment))
	{
		environment.changeHeater();
	}
}

void Agent::setBounds(double lower, double upper)
{
	std::pair<double, double> bounds = { lower, upper };
	bounds_ = bounds;
}