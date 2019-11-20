// dynamic.cpp  INCOMPLETE
// Glenn G. Chappell
// 13 Apr 2018
//
// For CS 201 Spring 2018
// Dynamic Allocation
//
// Modified 11/19/18
// Chris Hartman
// For CS 201 Fall 2018

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


// printThree
// Takes a pointer to an int array, which must have size at least 3 --
// or a null pointer. Prints the first three items in the array, or
// "NULL POINTER", if the passed pointer is null.
void printThree(int const * p)
{
    if (p == nullptr)
    {
        cout << "NULL POINTER" << endl;
    }
    else
    {
        cout << p[0] << " " << p[1] << " " << p[2] << endl;
    }
	delete[] p;
}


// Main Program
// Do some dynamic allocation. Call printThree multiple times.
int main()
{
    // Make a dynamic array of int, with size at least three. Set the
    // values of the first three items in the array.
    // Then call printThree, passing (a pointer to) the array.
	int* ap = new int[3];
	ap[0] = 10;
	ap[1] = 20;
	ap[2] = 30;
	printThree(ap);

    // Call printThree with a null pointer.
	printThree(nullptr);

    // Deallocate the dynamic array.


	/////////////// Because it deallocates in printThree, when I delete it here
	/////////////// my program crashes and an exception is thrown.

    
	// Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}

