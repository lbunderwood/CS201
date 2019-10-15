// Luke Underwood
// 10/15/19
// Header.h
// Header for Fifo-Lifo project (see fifo-lifo.cpp for details)

#ifndef HEADER_H
#define HEADER_H

//library inclusions
#include<iostream>
#include<vector>
#include<string>

//prototypes:
//Push to beginning or end
void lifoPush(std::vector<std::string>& container, const std::string& item);
void fifoPush(std::vector<std::string>& container, const std::string& item);

//remove from beginning or end
void fifoPop(std::vector<std::string>& container);
void lifoPop(std::vector<std::string>& container);

//general use
bool isContainerEmpty(const std::vector<std::string>& container);
void printContainer(const std::vector<std::string>& container);

//testing
bool fifoTest();
bool lifoTest();

#endif