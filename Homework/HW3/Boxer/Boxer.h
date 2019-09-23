/*
Luke Underwood
9/23/19
BoxPrint.cpp
Contains function boxPrint for Boxer.cpp

-----------------------------------------------
****Lie la lie, lie la la la lie lie
****Lie la lie, lie la la la la lie la la lie

-------Simon and Garfunkel's The Boxer--------

----------------------------------------------
*/

#include<iostream>
#include<string>

#ifndef BOXER_H
#define BOXER_H

void boxPrint(std::string message, int layers);

void firstLast(int layers, int columns);

void middle(int layers, int columns);

#endif
