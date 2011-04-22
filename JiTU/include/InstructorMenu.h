#ifndef __INSTRUCTORMENU__
#define __INSTRUCTORMENU__
#include "stdafx.h"
#include "User.h"
#include "ActivityMenu.h"
#include "InstructorContent.h"


using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;


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


#endif