// Image3.hpp
// Interface for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course

// Luke Underwood
// 12/8/19
// Mandelbrot project
// CS201
#ifndef IMAGE3_HPP
#define IMAGE3_CPP

#include <iostream>
#include <vector>
#include "Color3.hpp"

class Image3
{
public:
	Image3(unsigned width, unsigned height);
	
	void setPixel(unsigned x, unsigned y, const Color3& color);

	bool savePPM(const std::string& path) const;

	std::vector<Color3> pixels;
	unsigned w;
	unsigned h;
	Color3 borderColor;
};

std::ostream& operator<<(std::ostream& ostr, const Image3& image);

#endif
