//Just a classic hello world program. Prints Hello World
/*
Luke Underwood
8/30/19
*/

#include <iostream> //includes iostream file so we can use cin, cout, etc.

int main() //main area where program runs
{
	std::cout << "Hello World" << std::endl; //sends "hello world" to cout object in standard and ends line
	
	int a = 10; //sets up some variables
	int b = 15;
	int c = 10 * 15;
	std::cout << a << " multiplied by " << b << " equals " << c << std::endl; //prints what the variables did
	
	return 0; //causes main to return 0
}