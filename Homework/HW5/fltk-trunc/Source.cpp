//Luke Underwood
//10/23/19
//CS201
//Source.cpp
//fltk-trunc

//All standard headers that are used are included in truncstruct.hpp
#include"truncstruct.hpp"

//Include neccessary FlTk headers
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Int_Input.H>

//What do these do? No idea
#pragma comment (lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

//Declare foo and output globally so my functions can use them
StringInfo foo;
Fl_Output* Output = nullptr;

//callback function for truncate button
void truncPressed(Fl_Widget* w, void* data)
{
	//Error handling for nullptr
	if (!Output)
	{
		//print null to terminal for debugging purposes
		std::cout << "NULL" << std::endl;
		return;
	}
	//set value of output to a C string of the truncated string
	Output->value(trunc(foo).str.c_str());
}

void quitPressed(Fl_Widget* w, void* userdata) 
{
	//check for nullptr
	if (!userdata) return;

	// casts userdata to a Window
	Fl_Window* window = (Fl_Window*)userdata;

	// hide the window
	window->hide();
}

//callback function for text input
void wordTyped(Fl_Widget* w, void* data)
{
	//cast w to an input and set our string to its value
	Fl_Input* entry = (Fl_Input*)w;
	foo.str = entry->value();

	//output to terminal for debugging purposes
	std::cout << foo.str << std::endl;
}

//callback function for number input
void numTyped(Fl_Widget* w, void* data)
{
	//cast w to int input, set its value to a string
	Fl_Int_Input* entry = (Fl_Int_Input*)w;
	std::string str = entry->value();

	//convert string to an int
	std::istringstream instream(str);
	if (instream)
	{
		instream >> foo.len;

		//output to terminal for debugging
		std::cout << foo.len << std::endl;
	}

}

int main(int argc, char** argv) 
{
	//Create Window
	Fl_Window* window = new Fl_Window(340, 180, 640, 380, "FLTK-Truncator");

	//Welcome Message
	Fl_Box* welcome = new Fl_Box(20, 20, 600, 100, 
		"Enter a word, then a number, and press \"Truncate\" \nto make your "
		"word have that many letters!");
	welcome->box(FL_UP_BOX);
	welcome->labelfont(FL_BOLD + FL_ITALIC);
	welcome->labelsize(22);
	welcome->labeltype(FL_SHADOW_LABEL);

	//String input label
	Fl_Box* strlabel = new Fl_Box(20, 140, 290, 50, 
		"Word you would like to truncate:");
	strlabel->labelfont(FL_BOLD);
	strlabel->labelsize(18);
	strlabel->labeltype(FL_SHADOW_LABEL);

	//String input
	Fl_Input* strinput = new Fl_Input(20, 190, 290, 50);
	strinput->callback(wordTyped);

	//integer input label
	Fl_Box* intlabel = new Fl_Box(330, 140, 290, 50, "Number of letters:");
	intlabel->labelfont(FL_BOLD);
	intlabel->labelsize(18);
	intlabel->labeltype(FL_SHADOW_LABEL);

	//int intput
	Fl_Int_Input* intinput = new Fl_Int_Input(330, 190, 290, 50);
	intinput->callback(numTyped);

	//truncate button
	Fl_Return_Button* Button = new Fl_Return_Button(20, 310, 135, 50, "Truncate");
	Button->callback(truncPressed);

	Fl_Button* quitBtn = new Fl_Button(485, 310, 135, 50, "Quit");
	quitBtn->callback(quitPressed, (void*)window);
	
	//Output
	Output = new Fl_Output(175, 310, 290, 50);

	//Output Label
	Fl_Box* outlabel = new Fl_Box(175, 260, 290, 50, "New Word:");
	outlabel->labelfont(FL_BOLD);
	outlabel->labelsize(18);
	outlabel->labeltype(FL_SHADOW_LABEL);

	//Display widgets and run event loop
	window->end();
	window->show(argc, argv);
	return Fl::run();
}