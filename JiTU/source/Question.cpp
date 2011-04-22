#include "Question.h"

using namespace std;

#pragma region Question_ctor

Question::Question(int id) {

	this->id			= id;
	this->text			= new string;
	this->answers		= new Answer*;
	this->noOfAnswers	= 0;

}

#pragma endregion

#pragma region Question_get_Text

string Question::getText() {
	
	return *text;

}

#pragma endregion

#pragma region Question_add_Answer

void Question::addAnswer(Answer * answerIn) {

	Answer** temp	= answers;

	answers			= new Answer*[noOfAnswers + 1];

	for (int i = 0; i < noOfAnswers; i++)
		*(answers + i)	= *(temp + i);
	
	*(answers + noOfAnswers) = answerIn;

	delete temp;

	noOfAnswers++;

}

#pragma endregion

#pragma region Question_set_Text

void Question::setText(std::string textIn) {
	*(text) = textIn;
}

#pragma endregion

#pragma region Question_get_Answers

Answer** Question::getAnswers() {
	return answers;
}

#pragma endregion

#pragma region Question_get_count

int Question::getCount()	{
	return noOfAnswers;
}

#pragma endregion

