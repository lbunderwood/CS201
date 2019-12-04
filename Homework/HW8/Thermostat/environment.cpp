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


