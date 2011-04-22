#ifndef __STUDENTMENU__
#define __STUDENTMENU__
#include "User.h"
#include "stdafx.h"
#include "ActivityMenu.h"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;




ref class StudentMenu : ActivityMenu {

public:
	StudentMenu(User** userIn, Panel^ panelIn) : ActivityMenu(userIn, panelIn) {
		takeQuiz = gcnew Button();
		takeQuiz->Text = gcnew String("Take Quiz");
		takeQuiz->Font = buttonFont;
		takeQuiz->Height = 50;
		takeQuiz->BackgroundImage = buttonBack;
		takeQuiz->Dock = DockStyle::Top;
		Controls->Add(takeQuiz);
		takeQuiz->Click += gcnew EventHandler(this, &StudentMenu::takeQuizPressed);
		takeQuiz->FlatStyle = FlatStyle::Popup;

	}

private:
	Button^ takeQuiz;
	TakeQuizPanel^ quizing;
	void takeQuizPressed(Object^, EventArgs^);

};



#endif