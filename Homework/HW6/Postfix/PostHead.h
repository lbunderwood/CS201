/*
Luke Underwood
10/11/19
tokenizer.hpp
Contains function prototypes and library inclusions for tokenizer project
*/
// Updated 11/11/19
// Luke Underwood
// For Postfix Calculator project
// renamed PostHead.cpp
// CS201

#ifndef POSTHEAD_H
#define POSTHEAD_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>

bool readLine(std::string& line);

unsigned stringToTokens(std::vector<std::string>& tokens, std::string str);

void analyzeTokens(const std::vector<std::string>& tokens,
	std::vector<double>& numbers, std::vector<std::string>& operators);

void performOperation(std::vector<double>& numbers,
	std::vector<std::string>& operators);

void printVectors(std::vector<double> numbers,
	std::vector<std::string> operators);


#endif