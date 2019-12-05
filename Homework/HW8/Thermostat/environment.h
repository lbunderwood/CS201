// Luke Underwood
// 12/4/19
// environment.h
// Thermostat project
// CS201

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment
{
public:

	//Default constructor
	Environment();

	//Constructor with (double temp, bool heater), with true = heater on
	Environment(double temperature, bool heater);

	//Adjusts temperature based on current conditions
	void iteration();

	//returns the current temp
	double getTemperature();

	//returns the current heater status
	bool getHeater();

	//switches the heater on or off
	void changeHeater();

private:

	double temperature_;
	bool heaterOn_;
};

#endif