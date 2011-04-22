#include "Quiz.h"

using namespace std;


Question** Quiz::getQuestions() {
	return this->questions;
}


int Quiz::getCount() {
	return this->noOfQuestions;
}

Quiz::Quiz(int id)	{
	this->id = id;
	this->noOfQuestions = 0;
	this->questions = new Question*;
	this->title = new string;
}

void Quiz::addQuestion(Question *question) {
	Question** temp = this->questions;
	this->questions = new Question*[this->noOfQuestions + 1];
	for (int i = 0; i < this->noOfQuestions; i++) {
		*(this->questions + i) = *(temp + i);
	}
	*(this->questions + this->noOfQuestions) = question;
	delete temp;
	this->noOfQuestions++;

}


void Quiz::setTitle(string titleIn) {

	*title = titleIn;
}

string Quiz::getTitle() {
	return *(this->title);
}