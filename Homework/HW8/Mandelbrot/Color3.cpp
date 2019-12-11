// Color3.cpp
// Implementation for Color3 class
// Original Author: Jonathan Metzgar
// CS 201 course

// Luke Underwood
// 12/8/19
// Mandelbrot project
// CS201
#include <iomanip>
#include "Color3.hpp"

using std::setw;

// Ensure values are in the range 0 to maxvalue
constexpr int saturate(int x, int maxvalue) {
	return x < 0 ? 0 : x > maxvalue ? maxvalue : x;
}

Color3::Color3() : r(0), g(0), b(0) {}

Color3::Color3(int R, int G, int B) {
	r = (unsigned char)saturate(R, 255);
	g = (unsigned char)saturate(G, 255);
	b = (unsigned char)saturate(B, 255);
}

// Stream Operators for input and output

std::ostream& operator<<(std::ostream& ostr, const Color3& color) {
	ostr << setw(3) << (int)color.r << " ";
	ostr << setw(3) << (int)color.g << " ";
	ostr << setw(3) << (int)color.b << " ";
	return ostr;
}
