#ifndef __COURSE__
#define __COURSE__
#include "stdafx.h"
#include "Quiz.h"
#include <iostream>
#include <fstream>


using namespace cli;
using namespace std;

/************************************************************************************************
************************************************************************************************/

class Course {

public:
	Course		(int id);

	void		addQuiz(Quiz*);
	Quiz**		getQuizzes();
	int			getCount();
	string		getCourseName();
	void		setCourseName(string);

private:
	int			id;
	int			quizCount;
	string*		courseName;
	Quiz**		quizzes;

};


/************************************************************************************************
************************************************************************************************/



#endif