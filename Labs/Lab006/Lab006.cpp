/*
Luke Underwood
9/16/19
Lab006.cpp

*/

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//collects a string from the user and prints it
void stringInput()
{
	string input;
	int counter = 0;
	cout << "Please input a word\n";
	cin >> input;

	cout << "Your word: " << input << endl;
	cout << "Your word is ";
	for (counter = 0; counter < input.size(); counter++)
	{
		cout << "#";
	}
	cout << " letters long";
}

int main()
{
	stringInput();
	return 0;
}