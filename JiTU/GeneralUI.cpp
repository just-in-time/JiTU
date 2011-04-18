#include "GeneralUI.h"
#include <iostream>

using namespace cli;
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

/************************************************************************************************
************************************************************************************************/

GeneralUI::GeneralUI() : Form() {

	SuspendLayout();
	this->Height	= DEFAULT_HEIGHT;
	this->Width		= DEFAULT_WIDTH;

	createMenu();
	setIcon();

	this->mainUser	= new User*;
	enableLoginWindow();

	

	ResumeLayout();
}

/************************************************************************************************
************************************************************************************************/


void GeneralUI::createMenu() {
	
	mainMenu	= gcnew MenuStrip();

	fileItem	= gcnew ToolStripMenuItem(gcnew String("File"));
	exitItem	= gcnew ToolStripMenuItem(gcnew String("Exit"));
	
	helpItem	= gcnew ToolStripMenuItem(gcnew String("Help"));
	aboutItem	= gcnew ToolStripMenuItem(gcnew String("About"));

	exitItem->ShortcutKeys = Keys::Alt | Keys::Control | Keys::E;
	fileItem->Width = 2 * fileItem->Width;
	
	exitItem->TextAlign = Drawing::ContentAlignment::BottomLeft;

	mainMenu->Items->AddRange(gcnew array<ToolStripMenuItem^>(2) {
		fileItem,
		helpItem
	});

	fileItem->DropDownItems->Add(exitItem);
	helpItem->DropDownItems->Add(aboutItem);
	
	exitItem->Click += gcnew EventHandler(this, &GeneralUI::exitItemClicked);

	Controls->Add(mainMenu);

	mainMenu->Location = Point(0, 0);

}

/************************************************************************************************
************************************************************************************************/


void GeneralUI::enableLoginWindow() {

	login			 = gcnew LoginWindow(Width, Height, mainUser);
	login->Disposed += gcnew EventHandler(this, &GeneralUI::loggedIn);
	Controls->Add(login);
}

/************************************************************************************************
************************************************************************************************/

void GeneralUI::setIcon()	{
	Icon = gcnew Drawing::Icon(gcnew String("jitu.ico"));
	Text = gcnew String("Just In Time Ultimate");
}


/************************************************************************************************
************************************************************************************************/


void GeneralUI::exitItemClicked(Object^ sender, EventArgs^ e)	{
	Close();
}

/************************************************************************************************
************************************************************************************************/



void loadDummyData(User** userObject) {

	Course	*	temp		= new Course(0);
	Course	*	temp1		= new Course(1);
	Quiz	*	quiz1		= new Quiz(0);
	Quiz	*	quiz2		= new Quiz(1);
	Question*	quest1		= new Question(0);
	Answer	*	ans1		= new Answer(0);
	Answer	*	ans2		= new Answer(1);

	ans1->setText("blah1");
	ans1->setTrue();
	ans2->setText("This is just another Example");



	quest1->setText("Blah Question");
	quest1->addAnswer(ans1);
	quest1->addAnswer(ans2);
	quest1->addAnswer(ans2);
	quest1->addAnswer(ans2);
	quiz1->addQuestion(quest1);
	quiz1->setTitle("Quiz 1");
	for (int i = 0; i < 20; i++)
		quiz2->addQuestion(quest1);
	quiz2->setTitle("Quiz 2");
	temp->addQuiz(quiz1);
	temp->setCourseName("CSE201");
	temp1->addQuiz(quiz2);
	temp1->addQuiz(quiz1);
	temp1->setCourseName("CSE202");
	(*userObject)->addClass(temp);
	(*userObject)->addClass(temp1);

}



void GeneralUI::loggedIn(Object^ sender, EventArgs^ e) {

	content = gcnew ContentWindow(mainUser);
	loadDummyData(this->mainUser);
	logoutItem = gcnew ToolStripMenuItem(gcnew String("Logout"));
	
	fileItem->DropDownItems->Remove(exitItem);

	logoutItem->ShortcutKeys = Keys::Alt | Keys::Control | Keys::L;

	fileItem->DropDownItems->Add(logoutItem);
	fileItem->DropDownItems->Add(exitItem);
	logoutItem->Click += gcnew EventHandler(this, &GeneralUI::logoutItemClicked);
	content->Location = Point(0, mainMenu->Height);
	Controls->Add(content);

}


/************************************************************************************************
************************************************************************************************/

void GeneralUI::logoutItemClicked(System::Object ^sender, System::EventArgs ^e) {
	if (content) {
		delete content;
		delete *mainUser;
		delete logoutItem;

		enableLoginWindow();
	}
}

/************************************************************************************************
************************************************************************************************/