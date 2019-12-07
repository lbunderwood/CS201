// Luke Underwood
// 12/5/19
// Rule.cpp
// header file for Rule class for rule 30 update for HW8
// CS201

#ifndef RULE_H
#define RULE_H
#include<vector>
#include<string>

class Rule
{
public:
	//Constructor
	Rule(int columns, int rows, int ruleNum);

	//creates array of automata
	std::vector<std::vector<int>> createVector();

	//writes automata to file
	void writeFile(const std::string& path);

private:
	int ruleNum_ = 0;
	int rows_ = 0;
	int columns_ = 0;
};

#endif