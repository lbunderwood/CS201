// Created by Luke Underwood
// 11/26/19
// asciiart.cpp
// asciiart project
// CS201

#include "Color3.hpp"
#include "Image3.hpp"
#include<iostream>

int main()
{
	Image3 image;
	if (image.loadPPM("Fuji.PPM"))
	{
		image.printASCII(std::cout);
	}

	return 0;
}