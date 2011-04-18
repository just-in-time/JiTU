#include "Course.h"

using namespace std;

Course::Course(int idIn) {
	id = idIn;
	quizzes = new Quiz*;
	quizCount = 0;
	courseName = new string;
}

void Course::addQuiz(Quiz * quizIn) {
	Quiz** temp = this->quizzes;
	quizzes = new Quiz*[this->quizCount + 1];
	for (int i = 0; i < this->quizCount; i++) {
		*(this->quizzes + i) = *(temp + i);
	}
	*(quizzes + quizCount) = quizIn;
	quizCount++;
}


Quiz** Course::getQuizzes() {

	return this->quizzes;
}


int Course::getCount() {

	return this->quizCount;
}

string Course::getCourseName() {
	return *(this->courseName);
}

void Course::setCourseName(string  courseNameIn)	{

	courseName = new string(courseNameIn);

}