#include "StudentMenu.h"


void StudentMenu::takeQuizPressed(System::Object ^sender, System::EventArgs ^e) {
	this->quizing = gcnew TakeQuizPanel(this->mainUser, this->mainPanel->Width);
	this->mainPanel->Controls->Clear();
	this->mainPanel->Controls->Add(quizing);

}