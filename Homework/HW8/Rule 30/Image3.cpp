// Image3.hpp
// Implementation for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include "Image3.hpp"
#include<fstream>

// Image3 Constructor
Image3::Image3(unsigned width, unsigned height) {
	// TODO: resize the pixels array
	// TODO: initialize the internal w and h members
	w = width;
	h = height;
	pixels.resize(w * h);
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
	return pixels[y * w + x];
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) {
	// TODO: Set the pixel to the new color

}

bool Image3::savePPM(const std::string& path) const {
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	std::ofstream fout(path);
	if (fout)
	{
		fout << *this;
		return true;
	}
	return false;
}

bool Image3::loadPPM(const std::string& path) {
	// TODO: Load an image from the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	std::ifstream fin(path);
	if (fin && !fin.eof())
	{
		fin >> *this;
		return true;
	}
	return false;
}

void Image3::printASCII(std::ostream& ostr) const {
	// TODO: Print an ASCII version of this image
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
	int count = 0;
	int val;
	while (istr)
	{
		if (count >= image.pixels.size())
		{
			break;
		}
		istr >> val;
		if (val == 0)
		{
			image.pixels[count].r = 255;
			image.pixels[count].g = 255;
			image.pixels[count].b = 255;
		}
		else
		{
			image.pixels[count].r = 0;
			image.pixels[count].g = 0;
			image.pixels[count].b = 0;
		}
		count++;
	}
	return istr;
}
