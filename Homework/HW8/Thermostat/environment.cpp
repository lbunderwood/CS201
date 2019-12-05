// Luke Underwood
// 12/4/19
// environment.cpp
// Thermostat project
// CS201

#include "environment.h"

Environment::Environment() :
	temperature_(20), heaterOn_(false) {}

Environment::Environment(double temperature, bool heater) : 
	temperature_(temperature), heaterOn_(heater) {}

void Environment::iteration()
{
	if (heaterOn_)
	{
		temperature_++;
	}
	else
	{
		temperature_--;
	}
}

double Environment::getTemperature()
{
	return temperature_;
}

bool Environment::getHeater()
{
	return heaterOn_;
}

void Environment::changeHeater()
{
	heaterOn_ = !heaterOn_;
}

