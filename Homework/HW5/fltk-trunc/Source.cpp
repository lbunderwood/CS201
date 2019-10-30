//Luke Underwood
//10/23/19
//CS201


#include"truncstruct.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Int_Input.H>
#pragma comment (lib, "fltk.lib")


int main(int argc, char** argv) {
	

	Fl_Window* window = new Fl_Window(340, 180, 640, 380);
	StringInfo foo;
	//Welcome Message
	Fl_Box* welcome = new Fl_Box(20, 20, 600, 100, "Welcome to FLTK-truncator!");
	welcome->box(FL_UP_BOX);
	welcome->labelfont(FL_BOLD + FL_ITALIC);
	welcome->labelsize(36);
	welcome->labeltype(FL_SHADOW_LABEL);

	//String input label
	Fl_Box* strlabel = new Fl_Box(20, 140, 290, 50, "Word you would like to truncate:");
	strlabel->labelfont(FL_BOLD);
	strlabel->labelsize(18);
	strlabel->labeltype(FL_SHADOW_LABEL);

	//String input
	Fl_Input* strinput = new Fl_Input(20, 190, 290, 50);
	foo.str = strinput->value();

	//integer input label
	Fl_Box* intlabel = new Fl_Box(330, 140, 290, 50, "Number of letters:");
	intlabel->labelfont(FL_BOLD);
	intlabel->labelsize(18);
	intlabel->labeltype(FL_SHADOW_LABEL);

	//int intput
	Fl_Int_Input* intinput = new Fl_Int_Input(330, 190, 290, 50);
	

	//truncate button
	Fl_Return_Button* Button = new Fl_Return_Button(20, 260, 290, 100, "Truncate");
	Button->labelfont(FL_BOLD + FL_ITALIC);
	Button->labelsize(36);
	Button->labeltype(FL_SHADOW_LABEL);
	
	//Output Label
	Fl_Box* outlabel = new Fl_Box(330, 260, 290, 50, "New Word:");
	outlabel->labelfont(FL_BOLD);
	outlabel->labelsize(18);
	outlabel->labeltype(FL_SHADOW_LABEL);
	

	//Output
	Fl_Output* Output = new Fl_Output(330, 310, 290, 50);

	window->end();
	window->show(argc, argv);
	while (Fl::wait())
	{
		if (intinput->handle(FL_KEYDOWN))
		{
			char number = intinput->value()[0];
			number -= 48;
			foo.len = number;
		}

		if (Button->value())
		{
			Output->value(trunc(foo).str.data());
		}
	}
}