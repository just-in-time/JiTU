#ifndef __STUDENTCONTENT__
#define __STUDENTCONTENT__
#include "stdafx.h"
#include "Quiz.h"
#include "User.h"

using namespace cli;
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

/************************************************************************************************
************************************************************************************************/


ref class StudentContent : Panel {

public:
	 StudentContent (User** userIn) : Panel()	{
		mainUser = userIn;
		Dock = DockStyle::Fill;
		Padding = Forms::Padding(0, 25, 0, 0);

		this->AutoScroll = true;

		questionFont = gcnew Drawing::Font("Times New Roman", 16, FontStyle::Bold, GraphicsUnit::Pixel);
		answerFont = gcnew Drawing::Font("Times New Roman", 12, FontStyle::Italic, GraphicsUnit::Pixel);
		controlFont = gcnew Drawing::Font("MS Serif", 14, FontStyle::Bold, GraphicsUnit::Pixel);
		buttonBack = Image::FromFile(gcnew String("test_on.gif"));
		buttonFont = gcnew Drawing::Font("Lucida Console", 12, FontStyle::Regular, GraphicsUnit::Pixel);


	}

private:



protected:

	User**			mainUser;
	Drawing::Font^	questionFont;
	Drawing::Font^	answerFont;
	Drawing::Font^	controlFont;
	Drawing::Image^ buttonBack;
	Drawing::Font^	buttonFont;

};




/************************************************************************************************
************************************************************************************************/

ref class QuestionBox : GroupBox {

public:
	QuestionBox(Question*, int);

	virtual void OnResize(EventArgs^ e) override;

	property Answer* result {
		Answer* get();
	}

	
private:
	Label^					questionLabel;
	Label^					numberLabel;
	array<Label^>^			answerLabels;
	array<RadioButton^>^	answerButtons;
	property	Question*	questionPTR;
	property	Answer*		choicePTR;

	void onAnswerChanged (Object^ sender, EventArgs^ e);

};



/************************************************************************************************
************************************************************************************************/


ref class QuizViewPanel : StudentContent {

public:
	/**Constructor**/	QuizViewPanel		(User**, Quiz*);

	virtual void OnResize(EventArgs^ e) override;

private:
	array<QuestionBox^>^			questionGroups;
	Button^							submitButton;
	Button^							cancelButton;
	User**							mainUser;
	Quiz*							currentQuiz;
	

};

/************************************************************************************************
************************************************************************************************/

ref class SelectQuizItem : ListViewItem {

public: 
	SelectQuizItem() : ListViewItem () {}
	SelectQuizItem(String^ strIn, int imgIn, ListViewGroup^ grpIn) : ListViewItem(strIn, imgIn, grpIn) {}
	void		setQuiz(Quiz* quizIn) { quiz = quizIn; }
	Quiz*		getQuiz() { return quiz; }

private:
	Quiz*		quiz;


};

/************************************************************************************************
************************************************************************************************/

ref class SelectQuizPanel : ListView {

public:
	/**Constructor**/	SelectQuizPanel		(User**);
	
	virtual void OnResize(EventArgs^ e) override;
	array<ListViewGroup^>^			classes;
	array<array<SelectQuizItem^>^>^	quizzes;

private:
	User**							mainUser;



};




/************************************************************************************************
************************************************************************************************/





ref class TakeQuizPanel : StudentContent {

public:
	/**constructor**/	TakeQuizPanel		(User**, int);

	

private:
	User**				mainUser;
	SelectQuizPanel^	selectQuiz;
	QuizViewPanel^		quizView;

	void QuizSelected (Object^ sender, EventArgs^ e);

};




/************************************************************************************************
************************************************************************************************/



#endif