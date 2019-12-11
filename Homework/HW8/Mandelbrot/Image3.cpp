// Image3.hpp
// Implementation for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course

// Luke Underwood
// 12/8/19
// Mandelbrot project
// CS201
#include "Image3.hpp"
#include<fstream>

// Image3 Constructor
Image3::Image3(unsigned width, unsigned height) : w(width), h(height)
{
	pixels.resize(width * height);
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) 
{
	pixels[y * w + x] = color;
}

bool Image3::savePPM(const std::string& path) const {
	std::ofstream fout(path);
	if (fout)
	{
		fout << *this;
		return true;
	}
	else
	{
		return false;
	}
}

// STREAM OPERATOR for IMAGE3 class

std::ostream& operator<<(std::ostream& ostr, const Image3& image) {
	ostr << "P3" << std::endl
		<< image.w << " " << image.h << std::endl
		<< "255" << std::endl;
	for (auto n : image.pixels)
	{
		ostr << n << std::endl;
	}
	return ostr;
}