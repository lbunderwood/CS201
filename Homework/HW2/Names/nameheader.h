/*
Luke Underwood
9/16/19
nameheader.h
holds prototypes of functions
*/

#pragma once

#ifndef NAMEFUNCS_H
#define NAMEFUNCS_H

//takes the input from the user
void inputNames(std::vector<std::string>& names);

//searches the names
void searchNames(std::vector<std::string>& names, std::string search);

//prints the names
void printNames(std::vector<std::string>& names);

//sorts the names alphabetically
void sortNames(std::vector<std::string>& names);

#endif