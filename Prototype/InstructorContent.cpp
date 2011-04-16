#include "ContentWindow.h"
#include "ManagedToStd.h"

using namespace cli;
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;



/************************************************************************************************
************************************************************************************************/

InstructorContent::InstructorContent(User ** userIn) : Panel() {

	mainUser	= userIn;
	Dock		= DockStyle::Fill;
	BorderStyle	= Forms::BorderStyle::Fixed3D;
	BackColor	= Color::White;

	buttonBackground = Image::FromFile(gcnew String("class.png"));
	AutoScroll = true;

}

/************************************************************************************************
************************************************************************************************/

User** InstructorContent::user::get() {
	return mainUser;
}

/************************************************************************************************
************************************************************************************************/

void InstructorContent::user::set(User** userIn) {
	mainUser = userIn;
}

/************************************************************************************************
************************************************************************************************/


ManageQuizzesPanel::ManageQuizzesPanel(User ** userIn) : InstructorContent(userIn) {

	Label^ contentLabel = gcnew Label();
	contentLabel->Text = gcnew String("Your Courses and Quizzes");
	contentLabel->Font = gcnew Drawing::Font("Times New Roman", 16, FontStyle::Bold, GraphicsUnit::Pixel);
	contentLabel->AutoSize = true;
	contentLabel->Location = Point(20, 20);
	Controls->Add(contentLabel);

	Course** temp = (*(userIn))->getClasses();

	classes = gcnew array<ManageQuizList^>((*(userIn))->getClassCount());

	for (int i = 0; i < classes->Length; i++) {
		classes[i] = gcnew ManageQuizList((*(temp + i)));
		classes[i]->Height = 200;
		classes[i]->Location = Point(20, 50 + (i * 220));
		Controls->Add(classes[i]);
	}

}

/************************************************************************************************
************************************************************************************************/

Button^	ManageQuizList::createQuiz::get() {

	return createQuizButton;
}

/************************************************************************************************
************************************************************************************************/

#pragma region ManageQuizList

ManageQuizList::ManageQuizList(Course* courseIn) : SplitContainer() {

	this->AutoScroll = true;
	this->Dock = DockStyle::None;
	this->Panel1MinSize = 15;
	this->Orientation = Forms::Orientation::Horizontal;
	this->SplitterDistance = 15;
	this->IsSplitterFixed = true;
	Panel2->BackColor = Color::FromArgb(0xffdddddd);
	Panel1->BackColor = Color::Blue;


	quizPanel = gcnew ListView();
	ImageList^ imageLarge = gcnew ImageList();

	quizPanel->Dock = DockStyle::Fill;
	Drawing::Image^ blah = Image::FromFile(gcnew String("class.png"));
	imageLarge->Images->Add(blah);

	quizPanel->LargeImageList = imageLarge;

	quizPanel->View = View::LargeIcon;
	quizPanel->LargeImageList->ImageSize = Drawing::Size(50, 50);

	ListViewGroup^ viewGroup = gcnew ListViewGroup(ManagedToStd::toManaged(courseIn->getCourseName()));

	Quiz ** temp = courseIn->getQuizzes();

	quizItems = gcnew array<ManageQuizItem^>(courseIn->getCount());

	for (int i = 0; i < quizItems->Length; i++) {
		quizItems[i] = gcnew ManageQuizItem((*(temp + i)));
		quizItems[i]->Group = viewGroup;
		quizPanel->Items->Add(quizItems[i]);
	}

	quizPanel->Groups->Add(viewGroup);
	quizPanel->ShowGroups = true;

	createQuizButton = gcnew Button();


	Panel2->Controls->Add(quizPanel);


}

#pragma endregion

/************************************************************************************************
************************************************************************************************/

ManageQuizItem::ManageQuizItem(Quiz * quizIn) : ListViewItem(ManagedToStd::toManaged(quizIn->getTitle()), 0) {
	int_quiz = quizIn;
}

/************************************************************************************************
************************************************************************************************/

Quiz* ManageQuizItem::quiz::get() {
	return int_quiz;
};


/************************************************************************************************
************************************************************************************************/

#pragma region ManageQuizzesPanel

void ManageQuizzesPanel::OnResize(EventArgs^ e) {
	if (classes) {
		for (int i = 0; i < classes->Length; i++) {
			classes[i]->Width = Width - 40;
		}
	}
}

#pragma endregion

/************************************************************************************************
************************************************************************************************/

#pragma region quizzes_get

array<ManageQuizItem^>^ ManageQuizList::quizzes::get() {

	return this->quizItems;
}

#pragma endregion

/************************************************************************************************
************************************************************************************************/
