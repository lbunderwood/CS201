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

//Include FlTk Headers
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

//Include standard headers
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<sstream>

//Global variables
Fl_Output* bullOut = nullptr;
Fl_Output* cowOut = nullptr;
Fl_Output* scoreOut = nullptr;
Fl_Box* box = nullptr;
std::vector<int> number(4);
std::vector<int> guess(4);
int score = 0;

//Groups bull and cow values for convenience
struct Results
{
	int bulls = 0;
	int cows = 0;
};

//Returns the number of bulls and cows for the current guess
Results Result()
{
	Results thisGuess;
	//Checks for cows
	for (int numcount = 0; numcount < 4; numcount++)
	{
		for (int guesscount = 0; guesscount < 4; guesscount++)
		{
			if (guess[guesscount] == number[numcount] 
				&& guesscount != numcount)
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

//Resets the game
void newNumber()
{
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
}

//Callback for guess button
void buttonPressed(Fl_Widget* w, void* data)
{
	//Error handling for nullptr or invalid guess
	if (!bullOut || !cowOut || guess[0] == 10)
	{
		return;
	}

	//Send output to terminal to let the user view past guesses
	std::cout << "Guess: ";
	for (auto& n : guess)
	{
		std::cout << n;
	}
	std::cout << ", Bulls: " << Result().bulls << ", Cows: "
		<< Result().cows << std::endl;

	//set value of outputs to a C string of the number of bulls and cows
	bullOut->value(std::to_string(Result().bulls).c_str());
	cowOut->value(std::to_string(Result().cows).c_str());

	//Increase score
	score++;
	scoreOut->value(std::to_string(score).c_str());

	//Check for win
	if (Result().bulls == 4)
	{
		box->label("You Win! Press New Game to play again!");
	}
}

//Callback for new game button
void newPressed(Fl_Widget* w, void* data)
{
	//Reset number
	newNumber();

	//Reset score
	score = 0;

	//Reset outputs
	bullOut->value(std::to_string(0).c_str());
	cowOut->value(std::to_string(0).c_str());
	scoreOut->value(std::to_string(score).c_str());
	box->label("Welcome to Bulls and Cows! A Guessing game where you \n"
		"will try to guess a four digit number. With each guess, you \n"
		"will be told how many \"cows,\" or correct numbers in the \n"
		"wrong place you have, as well as how many \"bulls,\" or \n"
		"correct numbers in the correct place that you have. You win \n"
		"when you get four bulls. Try to get the lowest score possible!\n"
		"Tip: Your past guesses will appear in the terminal window.");
}

//Callback for quit button
void quitPressed(Fl_Widget* w, void* userdata) 
{
	//check for nullptr
	if (!userdata) return;

	// casts userdata to a Window
	Fl_Window* window = (Fl_Window*)userdata;

	// hide the window
	window->hide();
}

//callback function for number input
void numTyped(Fl_Widget* w, void* data)
{
	//cast w to int input, set its value to a string
	Fl_Int_Input* entry = (Fl_Int_Input*)w;
	std::string guessStr = entry->value();

	//Checks to make sure the string is a four digit number
	if (guessStr.size() != 4)
	{
		bullOut->value("INVALID INPUT");
		cowOut->value("INVALID INPUT");
		
		//This lets our guess button know to ignore the current guess
		guess[0] = 10; 
		return;
	}

	//If the input is good, assign it to the guess
	for (int i = 0; i < 4; i++)
	{
		guess[i] = guessStr[i] - 48;
	}

}

//Creates GUI and establishes callbacks
Fl_Window* CreateWindow() {
	
	//Sets up window
	Fl_Window* window = new Fl_Window(400, 50, 640, 480, "FLTK Bulls and Cows");
	
	//Draws instructions/win message box
	box = new Fl_Box(20, 40, 600, 200);
	box->box(FL_UP_BOX);
	box->labelsize(16);
	box->labeltype(FL_SHADOW_LABEL);
	box->label("Welcome to Bulls and Cows! A Guessing game where you \n"
		"will try to guess a four digit number. With each guess, you \n"
		"will be told how many \"cows,\" or correct numbers in the \n"
		"wrong place you have, as well as how many \"bulls,\" or \n"
		"correct numbers in the correct place that you have. You win \n"
		"when you get four bulls. Try to get the lowest score possible!\n"
		"Tip: Your past guesses will appear in the terminal window.");

	// We use these to ensure adequate spacing of widgets
	const int x = 100;
	int y = 250;
	const int w = 100;
	const int h = 25;
	const int Spacing = 10;

	//Initilize and set sizes of widgets
	Fl_Button* newBtn = new Fl_Button(x, y, w, h, "New Game");
	y += h + Spacing;
	Fl_Int_Input* Input = new Fl_Int_Input(x, y, 2 * w, h, "Input:");
	y += h + Spacing;
	Fl_Button* Guessbtn = new Fl_Button(x, y, w, h, "Guess");
	y += h + Spacing;
	bullOut = new Fl_Output(x, y, 2 * w, h, "Bulls: ");
	scoreOut = new Fl_Output(x + 3 * w + 2 * Spacing, y, w, h, "Score:" );
	y += h + Spacing;
	cowOut = new Fl_Output(x, y, 2 * w, h, "Cows:");
	y += h + Spacing;	
	Fl_Button* QuitBtn = new Fl_Button(x, y, w, h, "Quit");
	
	
	// Register callbacks
	Input->callback(numTyped);
	Guessbtn->callback(buttonPressed);
	newBtn->callback(newPressed);
	QuitBtn->callback(quitPressed, (void*)window);

	window->end();
	return window;
}

int main(int argc, char** argv)
{
	//Sets up game
	newNumber();

	//Draws window
	Fl_Window* window = CreateWindow();
	window->show(argc, argv);

	//Runs event loop
	return Fl::run();
}