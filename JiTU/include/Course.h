#ifndef __COURSE__
#define __COURSE__
#include "stdafx.h"
#include "Quiz.h"
#include <iostream>

using namespace cli;
using namespace std;

/**
*	Class Course:
*	
*	represents a university class object
*
*	----	DataMembers		----
*	id			-	course Identification
*	quizCount	-	number of quizzes for the class
*	courseName	-	Title of the course
*	quizzes		-	array of quiz pointers
*
*	----	Functions		----
*	Course		-	Constructor
*	addQuiz		-	Add a pointer to a quiz for this class
*	getQuizzes	-	return the quizzes that are assigned to class
*	getCount	-	return the number of quizzes assigned
*	getCourseN	-	return the course Name
*	setCourseN	-	set the Course Name
*/

class Course {

public:
	/**ctor **/	Course			(int);
	void		addQuiz			(Quiz*);
	Quiz**		getQuizzes		();
	int			getCount		();
	string		getCourseName	();
	void		setCourseName	(string);

private:
	int			id;
	int			quizCount;
	string*		courseName;
	Quiz**		quizzes;

};



#endif