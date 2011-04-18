#include "ContentWindow.h"


using namespace cli;
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;


/************************************************************************************************
************************************************************************************************/


void StudentMenu::takeQuizPressed(System::Object ^sender, System::EventArgs ^e) {
	this->quizing = gcnew TakeQuizPanel(this->mainUser, this->mainPanel->Width);
	this->mainPanel->Controls->Clear();
	this->mainPanel->Controls->Add(quizing);

}


/************************************************************************************************
************************************************************************************************/

void InstructorMenu::manageQuizzesClicked(System::Object ^, System::EventArgs ^) {

	manage = gcnew ManageQuizzesPanel(mainUser);
	mainPanel->Controls->Clear();
	mainPanel->Controls->Add(manage);
	

}