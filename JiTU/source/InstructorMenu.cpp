#include "InstructorMenu.h"


void InstructorMenu::manageQuizzesClicked(System::Object ^, System::EventArgs ^) {

	manage = gcnew ManageQuizzesPanel(mainUser);
	mainPanel->Controls->Clear();
	mainPanel->Controls->Add(manage);
	

}