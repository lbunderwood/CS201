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

