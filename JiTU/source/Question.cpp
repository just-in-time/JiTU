#include "Question.h"



string Question::getText() {
	return *text;

}


Question::Question(int id) {
	this->id = id;
	this->text = new string;
	this->answers = new Answer*;
	this->noOfAnswers = 0;
}

void Question::addAnswer(Answer * answerIn) {
	Answer** temp = this->answers;
	this->answers = new Answer*[this->noOfAnswers + 1];
	for (int i = 0; i < this->noOfAnswers; i++) {
		*(this->answers + i) = *(temp + i);
	}
	*(this->answers + this->noOfAnswers) = answerIn;
	delete temp;
	this->noOfAnswers++;
}

void Question::setText(std::string textIn) {
	*(this->text) = textIn;
}


Answer** Question::getAnswers() {
	return this->answers;
}

int Question::getCount()	{
	return this->noOfAnswers;
}

