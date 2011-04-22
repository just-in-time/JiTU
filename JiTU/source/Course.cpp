#include "Course.h"

using namespace std;

#pragma region Course_ctor

Course::Course		(int idIn) {
	id			= idIn;
	quizzes		= new Quiz*;
	quizCount	= 0;
	courseName	= new string;
}

#pragma endregion

#pragma region Course_add_Quiz

void Course::addQuiz(Quiz * quizIn) {

	Quiz** temp = quizzes;
	quizzes = new Quiz*[quizCount + 1];
	for (int i = 0; i < quizCount; i++) {
		*(quizzes + i) = *(temp + i);
	}
	*(quizzes + quizCount) = quizIn;
	delete temp;
	quizCount++;
}

#pragma endregion

#pragma region Course_get_Quiz

Quiz** Course::getQuizzes	() {

	return this->quizzes;

}

#pragma endregion

#pragma region Course_get_Count

int Course::getCount		() {

	return this->quizCount;

}

#pragma endregion

#pragma region Course_get_Coursename

string Course::getCourseName() {

	return *courseName;
}

#pragma endregion

#pragma region Course_set_Course_Name

void Course::setCourseName	(string  courseNameIn)	{

	courseName = new string(courseNameIn);

}

#pragma endregion

