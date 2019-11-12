// Luke Underwood
// 11/9/19
// RandoHead.h
// RandoMap
// Homework 6
// CS201
// Contains library inclusions and function prototypes for RandoMap project

#ifndef RANDOHEAD_H
#define RANDOHEAD_H

//Library inclusions
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

//Uniform Distrib
int randomBetweenU(int first, int last, std::mt19937& e2);

//Normal Distrib
int randomBetweenN(int mean, int radius, std::mt19937& e2);

//Using rand()
int randomBetween(int first, int last);

//Print map
void printDistrib(const std::map<int, int>& numbers);

#endif
