/*
Luke Underwood
11/1/19
bullcow.cpp
fltk-bullcow
CS201
Guessing game where the user tries to guess a four digit number. With each
guess, they are told how many "cows," or correct numbers in the wrong place
that they have, as well as how many bulls, or correct numbers in the correct
place that they have. Game starts over when they get four bulls.
Adapted to have a GUI using fltk
*/

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<sstream>
#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

Fl_Output* bullOut = nullptr;
Fl_Output* cowOut = nullptr;

std::vector<int> number(4);
std::vector<int> guess(4);

struct Results
{
	int bulls = 0;
	int cows = 0;
};

Results Result()
{
	Results thisGuess;
	//Checks for cows
	for (int numcount = 0; numcount < 4; numcount++)
	{
		for (int guesscount = 0; guesscount < 4; guesscount++)
		{
			if (guess[guesscount] == number[numcount] && guesscount != numcount)
			{
				thisGuess.cows++;
			}
		}
	}

	//Checks for bulls
	for (int numcount = 0; numcount < 4; numcount++)
	{
		if (guess[numcount] == number[numcount])
		{
			thisGuess.bulls++;
		}
	}

	return thisGuess;
}

void buttonPressed(Fl_Widget* w, void* data)
{
	//Error handling for nullptr
	if (!bullOut || !cowOut)
	{
		//print null to terminal for debugging purposes
		std::cout << "NULL" << std::endl;
		return;
	}

	//set value of outputs to a C string of the number of bulls and cows
	bullOut->value(std::to_string(Result().bulls).c_str);
	cowOut->value(std::to_string(Result().cows).c_str);

	if (Result().bulls == 4)
	{

	}
}


//callback function for number input
void numTyped(Fl_Widget* w, void* data)
{
	//cast w to int input, set its value to a string
	Fl_Int_Input* entry = (Fl_Int_Input*)w;
	std::string guessStr = entry->value();

	//convert string to an int
	std::istringstream instream(guessStr);
	for (int i = 0; i < 4; i++)
	{
		guess[i] = guessStr[i] - 48;
	}

}

Fl_Window* CreateWindow() {
	Fl_Window* window = new Fl_Window(640, 480);
	Fl_Box* box = new Fl_Box(20, 40, 600, 100, "Bulls and Cows");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);

	// We use these to ensure adequate spacing of widgets
	const int x = 100;
	int y = 160;
	const int w = 100;
	const int h = 25;
	const int Spacing = 10;

	//Initilize and set sizes of widgets
	Fl_Int_Input* Input = new Fl_Int_Input(x, y, 2 * w, h, "Input");
	y += h + Spacing;
	Fl_Button* Guessbtn = new Fl_Button(x, y, w, h, "Process");
	y += h + Spacing;
	bullOut = new Fl_Output(x, y, 2 * w, h, "Bulls: ");
	y += h + Spacing;
	cowOut = new Fl_Output(x, y, 2 * w, h, "Cows: ");
	
	// Register callbacks
	Input->callback(numTyped);
	Guessbtn->callback(buttonPressed);

	window->end();
	return window;
}

int main()
{
	CreateWindow();

	//Print out some instructions for the user
	std::cout << "Welcome to Bulls and Cows! A Guessing game where you "
			<< "will try to guess a four digit number. With each guess, you "
			<< "will be told how many \"cows,\" or correct numbers in the "
			<< "wrong place you have, as well as how many \"bulls,\" or "
			<< "correct numbers in the correct place that you have. The game "
			<< "starts over when you get four bulls. Your score is the number "
			<< "of turns you took, so try to get the lowest score possible!" 
			<< std::endl;

		//Sets our number to be four unique random integers 0 to 9
		number = { 10, 10, 10, 10 };
		for (int i = 0; i < 4; i++)
		{
			srand(time(NULL));
			int num = rand() % 10;
			while (number[0] == num || number[1] == num 
				|| number[2] == num || number[3] == num)
			{
				num = rand() % 10;
			}
			number[i] = num;
		}

		
		if (score < highscore || highscore == 0)
			highscore = score;

		//Victory message
		std::cout << "Congratulations! You Win!\n" 
			<< "Your score: " << score << ", High score: " 
			<< highscore << std::endl;

		
	}
}