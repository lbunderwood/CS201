/*
Luke Underwood
10/11/19
tokenizer.hpp
Contains function prototypes and library inclusions for tokenizer project
*/

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>

bool readLine(std::string& str);

unsigned stringToTokens(std::vector<std::string>& tokens, std::string str);
#endif