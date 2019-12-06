// Luke Underwood
// 12/5/19
// Rule.cpp
// source file for Rule class for rule 30 update for HW8
// CS201

#ifndef RULE_H
#define RULE_H
#include<vector>

class Rule
{
public:
	//Constructors
	Rule();
	Rule(int rows, int columns, int ruleNum);

	std::vector<std::vector<int>> createVector();

private:
	int ruleNum_ = 0;
	int rows_ = 0;
	int columns_ = 0;
};

#endif