// Luke Underwood
// 10/15/19
// Header.h
// Header for Fifo-Lifo project (see fifo-lifo.cpp for details)

#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<vector>
#include<string>

void Push(std::vector<std::string>& container, const std::string& item);

void fifoPop(std::vector<std::string>& container);
void lifoPop(std::vector<std::string>& container);

bool isContainerEmpty(const std::vector<std::string>& container);
void printContainer(const std::vector<std::string>& container);

bool fifoTest();
bool lifoTest();

#endif