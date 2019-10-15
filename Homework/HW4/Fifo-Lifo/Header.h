// Luke Underwood
// 10/15/19
// Header.h
// Header for Fifo-Lifo project (see fifo-lifo.cpp for details)

#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<vector>
#include<string>

void fifoPush();
void fifoPop();

void lifoPush();
void lifoPop();

bool isContainerEmpty();
void printContainer();

bool fifoTest();
bool lifoTest();

#endif