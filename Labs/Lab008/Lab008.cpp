/*
Luke Underwood
9/20/19
Lab008.cpp
contains functions for lab8_main
*/

#include<iostream>
#include<cmath>
#include"intio.hpp"
#include"lab8.hpp"

//this function is straight up a bad coding practice. So redundant
int doInput()
{
	return getInt();
}

//returns either 0 or the number of factors not including itself
int compute(int n)
{
	int factors = 0;
	if (n <= 0)
	{
		return 0;
	} else {
		for(int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				factors++;
			}
		}
		return factors;
	}

}