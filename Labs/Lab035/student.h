#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<iostream>

class Student 
{
public:
	Student() : name_{ "DEFAULT NAME" }, id_{ 1000 } {}

	Student(std::string name, int id) : name_{ name }, id_{ id } {}

	Student(std::string name) : name_{ name }, id_{ 1000 } {}

	void printInfo() const;

private:
	std::string name_;
	int id_;
};

#endif