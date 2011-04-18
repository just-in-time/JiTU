#ifndef __INSTRUCTORCONTENT__
#define __INSTRUCTORCONTENT__

#include "stdafx.h"
#include "StudentContent.h"
#include "Course.h"
#include "User.h"
#include "Quiz.h"


using namespace cli;
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

/************************************************************************************************
************************************************************************************************/


ref class InstructorContent : Panel {

public:
	InstructorContent(User**);

	property User** user {
		void	set(User**);
		User**	get();
	}


protected:

	property User**		mainUser;
	
	Drawing::Font^		buttonFont;
	Drawing::Image^		buttonBackground;

};




/************************************************************************************************
************************************************************************************************/

ref class ManageQuizItem : ListViewItem {

public:
	ManageQuizItem(Quiz*);

	property Quiz* quiz {
		Quiz* get();
	}

private:
	property Quiz*	int_quiz;


};

/************************************************************************************************
************************************************************************************************/

ref class ManageQuizList : SplitContainer {

public:
	ManageQuizList(Course*);

	property Button^ createQuiz {
		Button^ get();
	}

	property array<ManageQuizItem^>^ quizzes {
		array<ManageQuizItem^>^ get();
	}

private:
	property Button^			createQuizButton;
	property ListView^			quizPanel;
	array<ManageQuizItem^>^		quizItems;

};

/************************************************************************************************
************************************************************************************************/

ref class ManageQuizzesPanel : InstructorContent {

public:
	ManageQuizzesPanel(User**);

	virtual void OnResize(EventArgs^ e) override;


private:

	array<ManageQuizList^>^	classes;

};


/************************************************************************************************
************************************************************************************************/


#endif