#include "StudentContent.h"
#include "ManagedToStd.h"
#include <iostream>

using namespace std;



TakeQuizPanel::TakeQuizPanel(User** userIn, int wIn) : StudentContent(userIn) {

	this->selectQuiz = gcnew SelectQuizPanel(userIn);
	this->selectQuiz->ItemActivate += gcnew EventHandler(this, &TakeQuizPanel::QuizSelected);
	this->Controls->Add(selectQuiz);


}

 void SelectQuizPanel::OnResize(System::EventArgs ^e)  {


	 
}


SelectQuizPanel::SelectQuizPanel(User** userIn) {

	Dock = DockStyle::Fill;
	this->Padding = Forms::Padding(0, 30, 0, 0);
	Course** temp = (*userIn)->getClasses();
	this->View = Forms::View::LargeIcon;
		
	ImageList^ largeImages = gcnew ImageList();
	largeImages->Images->Add(Image::FromFile(gcnew String("test_on.gif")));
	largeImages->ImageSize = Drawing::Size(50, 50);
	LargeImageList = largeImages;
	

	this->Columns->Add(gcnew String("classes"), gcnew String("Course"));

	classes = gcnew array<ListViewGroup^>((*userIn)->getClassCount());
	quizzes = gcnew array<array<SelectQuizItem^>^>(classes->Length);

	this->Groups->Clear();

	for (int i = 0; i < classes->Length; i++) {
		classes[i] = gcnew ListViewGroup(ManagedToStd::toManaged((*(temp + i))->getCourseName()), HorizontalAlignment::Left);
		this->Groups->Add(classes[i]);
	}

	this->Activation = ItemActivation::TwoClick;


	for (int i = 0; i < quizzes->Length; i++) {
		Quiz** tempQuizzes = (*(temp + i))->getQuizzes();
		quizzes[i] = gcnew array<SelectQuizItem^>((*(temp + i))->getCount());
		for (int j = 0; j < quizzes[i]->Length; j++) {
			quizzes[i][j] = gcnew SelectQuizItem(ManagedToStd::toManaged((*(tempQuizzes + j))->getTitle()), 0, classes[i]);
			quizzes[i][j]->setQuiz((*(tempQuizzes + j)));
			Items->Add(quizzes[i][j]);
		}

	}
	
	this->ShowGroups = true;
	

}


/************************************************************************************************
************************************************************************************************/

void TakeQuizPanel::QuizSelected (Object^ sender, EventArgs^ e) {
	array<array<SelectQuizItem^>^>^ temp = this->selectQuiz->quizzes;

	for (int i = 0; i < temp->Length; i++) {
		for (int j = 0; j < temp[i]->Length; j++) {
			if (temp[i][j]->Selected)
				quizView = gcnew QuizViewPanel(mainUser, temp[i][j]->getQuiz());
		}
	}
	delete selectQuiz;
	Controls->Add(quizView);
}

/************************************************************************************************
************************************************************************************************/


QuizViewPanel::QuizViewPanel(User ** userIn, Quiz * selectedQuiz) :  StudentContent(userIn) {
	
	Question** tempQ = selectedQuiz->getQuestions();


	this->currentQuiz = selectedQuiz;

	BackColor = Color::White;

	Label^ panelLabel = gcnew Label();
	panelLabel->Text = ManagedToStd::toManaged(selectedQuiz->getTitle());
	panelLabel->Font = this->controlFont;
	panelLabel->Location = Point(20, 20);
	Controls->Add(panelLabel);
	


	questionGroups = gcnew array<QuestionBox^>(selectedQuiz->getCount());

	for(int i = 0; i < questionGroups->Length; i++){
		int answers = (*(tempQ + i))->getCount();
		questionGroups[i] = gcnew QuestionBox((*(tempQ + i)), i);
		questionGroups[i]->Height = 100 + (answers * 40);
		questionGroups[i]->Width = 300;
		questionGroups[i]->Location = Point(20, 50 + (i * ((answers * 40) + 120)));
		Controls->Add(questionGroups[i]);
	}
	
	submitButton = gcnew Button();
	cancelButton = gcnew Button();
	submitButton->Text = gcnew String("Submit");
	cancelButton->Text = gcnew String("Cancel");
	submitButton->Font = this->buttonFont;
	cancelButton->Font = this->buttonFont;

	submitButton->Width = 100;
	cancelButton->Width = 100;
	submitButton->Height = 40;
	cancelButton->Height = 40;
	submitButton->TextAlign = ContentAlignment::MiddleCenter;
	cancelButton->TextAlign = ContentAlignment::MiddleCenter;

	submitButton->BackColor = Color::Black;
	cancelButton->BackColor = Color::Black;

	submitButton->ForeColor = Color::White;
	cancelButton->ForeColor = Color::White;

	submitButton->FlatStyle = FlatStyle::Popup;
	cancelButton->FlatStyle = FlatStyle::Popup;

	cancelButton->Location = Point(Width - 170, Height - 50);
	submitButton->Location = Point(Width - 40, Height - 50);

	Controls->Add(submitButton);
	Controls->Add(cancelButton);

}


/************************************************************************************************
************************************************************************************************/

void QuizViewPanel::OnResize(EventArgs^ eventArgs) {

	AutoScroll = false;
	if (questionGroups)	{
		if (questionGroups[questionGroups->Length -1]->Location.Y > Height) {
			for (int i = 0; i < questionGroups->Length; i++)
				questionGroups[i]->Width = Width - 50;
			AutoScroll = true;
			cancelButton->Location = Point(Width - 250, questionGroups[questionGroups->Length -1 ]->Location.Y + questionGroups[questionGroups->Length -1]->Height + 20);
			submitButton->Location = Point(Width - 135, questionGroups[questionGroups->Length -1 ]->Location.Y + questionGroups[questionGroups->Length -1]->Height + 20);
			this->AutoScrollMargin = Drawing::Size(0, 20);
		}
		else {
			for (int i = 0; i < questionGroups->Length; i++)
				questionGroups[i]->Width = Width - 40;
			cancelButton->Location = Point(Width - 250, Height - 50);
			submitButton->Location = Point(Width - 135, Height - 50);
		}
	}

}


/***********************************************************************************************
***********************************************************************************************/



QuestionBox::QuestionBox(Question * questIn, int i) : GroupBox() {

	questionPTR = questIn;

	numberLabel = gcnew Label();

	BackColor = Color::FromArgb(0xFFEEEEEE);

	numberLabel->Text = gcnew String("Question " + (i + 1));
	numberLabel->ForeColor = Color::FromArgb(0xFFffcb66);
	numberLabel->BackColor = Color::FromArgb(0xff990033);
	numberLabel->Height = 25;
	numberLabel->Width = Width - 40;
	numberLabel->Location = Point(20, 20);
	numberLabel->TextAlign = ContentAlignment::MiddleCenter;
	numberLabel->Font = gcnew Drawing::Font("Times New Roman", 14, FontStyle::Bold, GraphicsUnit::Pixel);
	Controls->Add(numberLabel);

	questionLabel = gcnew Label();
	questionLabel->Text = ManagedToStd::toManaged(questionPTR->getText());
	questionLabel->Font = gcnew Drawing::Font("Times New Roman", 14, FontStyle::Bold, GraphicsUnit::Pixel);
	questionLabel->AutoSize = true;
	questionLabel->Location = Point(20, 60);
	Controls->Add(questionLabel);

	Answer** temp = questionPTR->getAnswers();

	answerLabels = gcnew array<Label^>(questionPTR->getCount());
	answerButtons = gcnew array<RadioButton^>(questionPTR->getCount());

	for (int i = 0; i < answerLabels->Length; i++) {
		answerLabels[i] = gcnew Label();
		answerButtons[i] = gcnew RadioButton();
		answerButtons[i]->Location = Point(20, (90 + (i * 40)));
		answerButtons[i]->Text =  ManagedToStd::toManaged((*(temp + i))->getText());
		answerButtons[i]->AutoSize = true;
		answerButtons[i]->Font	= gcnew Drawing::Font("Times New Roman", 12, FontStyle::Italic, GraphicsUnit::Pixel);
		answerLabels[i]->Font = gcnew Drawing::Font("Times New Roman", 12, FontStyle::Italic, GraphicsUnit::Pixel);
		answerLabels[i]->AutoSize = true;
		answerLabels[i]->TextAlign = ContentAlignment::BottomLeft;
		answerLabels[i]->Location = Point(40, 91 + (i * 40));
		Controls->Add(answerLabels[i]);
		Controls->Add(answerButtons[i]);
	}



};



Answer* QuestionBox::result::get() {
	return this->choicePTR;
}

void QuestionBox::onAnswerChanged(System::Object ^sender, System::EventArgs ^e) {

}

void QuestionBox::OnResize(System::EventArgs ^e) {
	if (numberLabel)
		numberLabel->Width = Width - 40;

}

