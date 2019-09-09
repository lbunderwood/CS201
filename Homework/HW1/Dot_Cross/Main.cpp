/*
Luke Underwood
9/5/2019
Dot Cross
Takes two vectors and prints their dot and cross products
*/

#include <iostream>
#include <iomanip>

int main() 
{
	//declare variables
	float x1input;
	float y1input;
	float z1input;
	float x2input;
	float y2input;
	float z2input;
	float dot;
	float xcross;
	float ycross;
	float zcross;

	//gather the info
	std::cout << "Please enter your first vector's X value\n";
	std::cin >> x1input;
	std::cout << "Please enter your first vector's Y value\n";
	std::cin >> y1input;
	std::cout << "Please enter your first vector's Z value\n";
	std::cin >> z1input;
	std::cout << "Please enter your second vector's X value\n";
	std::cin >> x2input;
	std::cout << "Please enter your second vector's Y value\n";
	std::cin >> y2input;
	std::cout << "Please enter your second vector's Z value\n";
	std::cin >> z2input;

	//calculate the products
	dot = x1input * x2input + y1input * y2input + z1input * z2input;
	xcross = y1input * z2input - y2input * z1input;
	ycross = x2input * z1input - x1input * z2input;
	zcross = x1input * y2input - x2input * y1input;

	//Set decimal places to 5
	std::cout << std::setprecision(5);

			  //output the dot product
	std::cout << "< " << x1input << ", " << y1input << ", " << z1input
			  << " > o < " << x2input << ", " << y2input << ", " << z2input
			  << " > = " << dot << std::endl
			  //output the cross product
			  << "< " << x1input << ", " << y1input << ", " << z1input 
			  << " > X < " << x2input << ", " << y2input << ", " << z2input
			  << " > = < " << xcross << ", " << ycross << ", " << zcross
			  << " >";

	return 0;
}