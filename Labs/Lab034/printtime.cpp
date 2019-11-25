// printtime.cpp  INCOMPLETE
// Glenn G. Chappell
// 20 Apr 2018
//
// For CS 201 Spring 2018
// Time of Day Class & Program
//
// Modified 11/28/18 for CS 201 Fall 2018
// Chris Hartman

// Luke Underwood
// Lab 34
// CS 201

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>


// Class Time
// Holds a time of day: hours, minutes, seconds. Can print its stored
// time in a nice format.
class Time {

public:
// ***** Time: constructors *****

	Time() : _hr{ 0 }, _min{ 0 }, _sec{ 0 } {}

	Time(int hr, int min, int sec) : _hr{ hr }, _min{ min }, _sec{ sec } {}
// ***** Time: general public member functions *****

    void print() const //WHEN NOT CONST: "cannot convert 'this' pointer from 'const Time' to 'Time &'"
    {
        cout << std::setfill('0') << std::setw(2) << _hr << ":" << std::setw(2) << _min << ":" << std::setw(2) << _sec;
    }

// ***** Time: data members *****
private:

    int _hr;   // Hours past midnight
    int _min;  // Minutes past the hour
    int _sec;  // Seconds past the minute

};  // End class Time


int main()
{
    // Print header
    cout << "Here are some times:" << endl;
    cout << endl;

    // Make a Time object; print it
    const Time t1;
    cout << "Time #1: [";
    t1.print();
    cout << "]" << endl;
    cout << endl;

	Time t2(4,10,42);
	cout << "Time #2: [";
	t2.print();
	cout << "]" << endl;
	cout << endl;

    // Wait for user
    cout << "PRESS ENTER to quit ";
    while (cin.get() != '\n') ;
}

