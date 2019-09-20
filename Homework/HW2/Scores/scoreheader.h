/*
Luke Underwood
9/20/19
scoreheader.h
holds prototypes of functions
*/

#pragma once

#ifndef NAMEFUNCS_H
#define NAMEFUNCS_H

//takes the input from the user
void inputScores(std::vector<std::string>& names, std::vector<int>& scores);

//prints the names
void printScores(std::vector<std::string>& names, std::vector<int>& scores);

//searches the names
bool searchNames(std::vector<std::string>& names, 
		std::string searchs, int& searchi);

//searches the scores
bool searchScores(std::vector<int>& scores, int& search);

#endif