#ifndef __CONTENTWINDOW__
#define __CONTENTWINDOW__
#include "User.h"
#include "stdafx.h"
#include "StudentContent.h"
#include "InstructorContent.h"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

/************************************************************************************************
************************************************************************************************/

ref class ActivityMenu : Panel {

public:
	ActivityMenu(User** userIn, Panel^ contentIn) : Panel() {
		mainUser	= userIn;
		Dock		= DockStyle::Fill;
		mainPanel	= contentIn;
		Padding		= Forms::Padding(0, 25, 0, 0);
		mainPanel->Padding = Forms::Padding(0, 25, 0, 0);
		BackColor	= Color::FromArgb(0xffcf6c4e);
		buttonBack	= Drawing::Image::FromFile(gcnew String("button_back.png"));
		buttonFont	= gcnew Drawing::Font("Lucida Console", 16 , FontStyle::Bold, GraphicsUnit::Pixel);

		
	}

protected:
	Panel^			mainPanel;
	User**			mainUser;
	Image^			buttonBack;
	Drawing::Font^	buttonFont;

};

/************************************************************************************************
************************************************************************************************/


ref class InstructorMenu : ActivityMenu {

private: 
	void manageQuizzesClicked(Object^, EventArgs^);

public:
	InstructorMenu(User** userIn, Panel^ panelIn) : ActivityMenu(userIn, panelIn) {
	
		manageQuizzes = gcnew Button();
		manageUsers = gcnew Button();

		manageQuizzes->Text = gcnew String("Manage Quizzes");
		manageUsers->Text = gcnew String("Manage Users");

		manageQuizzes->Height = 50;
		manageUsers->Height = 50;

		manageQuizzes->FlatStyle = FlatStyle::Popup;
		manageUsers->FlatStyle = FlatStyle::Popup;

		manageQuizzes->BackgroundImage = buttonBack;
		manageUsers->BackgroundImage = buttonBack;

		manageQuizzes->Font = buttonFont;
		manageUsers->Font = buttonFont;

		manageQuizzes->Dock = DockStyle::Top;
		manageUsers->Dock = DockStyle::Top;

		Controls->AddRange(gcnew array<Button^>(2) {
			manageUsers,
			manageQuizzes
		});
		
		manageQuizzes->Click += gcnew EventHandler(this, &InstructorMenu::manageQuizzesClicked);
	}

private:

	ManageQuizzesPanel^	manage;

	Button^ manageQuizzes;
	Button^ manageUsers;



};


/************************************************************************************************
************************************************************************************************/

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


/************************************************************************************************
************************************************************************************************/

ref class ContentWindow : SplitContainer {

public:
	ContentWindow(User** userIn) : SplitContainer() {

		mainUser = userIn;
		Dock = DockStyle::Fill;
		SplitterDistance = 25;

		Panel1->BackColor = Color::FromArgb(0xffe9a05b);

		if (!(*mainUser)->getRole())
			nav = gcnew InstructorMenu(userIn, Panel2);
		else
			nav = gcnew StudentMenu(userIn, Panel2);

		this->IsSplitterFixed = true;
		Panel1->Controls->Add(nav);
		Panel1->BorderStyle = Forms::BorderStyle::FixedSingle;
		BorderStyle = Forms::BorderStyle::None;

	}

private:
	User**			mainUser;
	ActivityMenu^	nav;
	Image^			panelBack;

};

/************************************************************************************************
************************************************************************************************/




#endif