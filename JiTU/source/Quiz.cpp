#include "Quiz.h"

using namespace std;

#pragma region Quiz_get_Questions

Question** Quiz::getQuestions() {
	return questions;
}

#pragma endregion

#pragma region Question_get_Count

int Quiz::getCount() {
	return noOfQuestions;
}

#pragma endregion

#pragma region Quiz_ctor

Quiz::Quiz	(int idIn)	{
	id				= idIn;
	noOfQuestions	= 0;
	questions		= new Question*;
	title			= new string;
}

#pragma endregion

#pragma region Quiz_add_Question

void Quiz::addQuestion(Question *question) {

	Question** temp = questions;
	questions		= new Question*[noOfQuestions + 1];

	for (int i = 0; i < this->noOfQuestions; i++) 
		*(questions + i) = *(temp + i);
	
	*(questions + noOfQuestions) = question;
	
	noOfQuestions++;

	delete temp;
}

#pragma endregion

#pragma region Quiz_set_Title

void Quiz::setTitle(string titleIn) {

	*title = titleIn;

}

#pragma endregion

#pragma region Quiz_get_Title

string Quiz::getTitle() {
	return *title;
}

#pragma endregion