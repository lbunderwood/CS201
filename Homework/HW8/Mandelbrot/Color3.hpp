// Color3.hpp
// Interface for Color3 class
// Original Author: Jonathan Metzgar
// CS 201 course

// Luke Underwood
// 12/8/19
// Mandelbrot project
// CS201
#ifndef COLOR3_HPP
#define COLOR3_HPP

#include <iostream>

class Color3
{
public:
	Color3();
	Color3(int R, int G, int B);

	unsigned char r;
	unsigned char g;
	unsigned char b;
};

std::ostream& operator<<(std::ostream& ostr, const Color3& color);

#endif
