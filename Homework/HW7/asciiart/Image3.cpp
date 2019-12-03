// Image3.hpp
// Implementation for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course

// Modified by Luke Underwoood

#include "Image3.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

// Image3 Constructor
Image3::Image3(unsigned width, unsigned height) {
	// TODO: resize the pixels array
	// TODO: initialize the internal w and h members
	w = width;
	h = height;
	pixels.resize(width * height);
}

// Default Image3 Constructor
Image3::Image3() {
	// TODO: resize the pixels array
	// TODO: initialize the internal w and h members
	w = 0;
	h = 0;
	pixels.resize(0);
}

// Return a pixel from the image
const Color3& Image3::getPixel(unsigned x, unsigned y) const {
	// TODO: Add error handling for unknown pixels
	// TERRIBLE OPTION 1: throw
	// BETTER OPTION 2: return a color
	// Hint: maybe this is already in the class?
	if (y * w + x > pixels.size())
	{
		return pixels.back();
	}
	else
	{
		return pixels[y * w + x];
	}
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) {
	// TODO: Set the pixel to the new color
	pixels[y * w + x] = color;
}

bool Image3::savePPM(const std::string& path) const {
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	std::ofstream fout(path);
	if (fout)
	{
		fout << *this;
	}
	return false;
}

bool Image3::loadPPM(const std::string& path) {
	// TODO: Load an image from the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	std::ifstream fin(path);
	if (fin)
	{
		fin >> *this;
		return true;
	}
	return false;
}

void Image3::printASCII(std::ostream& ostr) const {
	// TODO: Print an ASCII version of this image
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			ostr << getPixel(j,i).asciiValue();
		}
		std::cout << std::endl;
	}
}

// STREAM OPERATORS for IMAGE3 class

std::ostream& operator<<(std::ostream& ostr, const Image3& image) {
	// TODO: Write out PPM image format to stream
	// ASSUME FORMAT WILL BE GOOD
	ostr << "P3" << std::endl 
		<< image.w << " " << image.h << std::endl 
		<< "255" << std::endl;

	for (auto n : image.pixels)
	{
		ostr << n.r << " " << n.g << " " << n.b << std::endl;
	}
	return ostr;
}

std::istream& operator>>(std::istream& istr, Image3& image) {
	// TODO: Read in PPM image format from stream
	// MAKE SURE FORMAT IS GOOD!!!
	
	std::string line;
	std::getline(istr, line);

	if (line != "P3")
	{
		std::cout << "INCORRECT FORMAT";
		return istr;
	}

	bool setMax = false;
	std::vector<int> colors;
	int count = 0;

	while (istr)
	{
		std::getline(istr, line);
		if (line[0] == '#' || line == "")
		{
			continue;
		}
		std::istringstream instream(line);
		int value;
		instream >> value;
		if (instream)
		{
			if (image.w == 0 && image.h == 0)
			{
				image.w = value;
				instream >> value;
				image.h = value;
				image.pixels.resize(image.w * image.h);
			}
			else if (!setMax)
			{
				if (value != 255)
				{
					std::cout << "INCORRECT FORMAT";
					break;
				}
				setMax = true;
			}
			else if (colors.size() < 3)
			{
				colors.push_back(value);
				if (colors.size() == 3)
				{
					image.pixels[count].r = colors[0];
					image.pixels[count].g = colors[1];
					image.pixels[count].b = colors[2];
					colors.clear();
					count++;
				}
			}

		}
		else
		{
			std::cout << "BAD INPUT";
			break;
		}
		
	}
	return istr;
}
