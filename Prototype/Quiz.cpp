#include "Quiz.h"

using namespace std;


string Question::getText() {
	return *text;

}


Answer::Answer(int id) {
	this->id = 0;
	this->correct = false;
	this->text = new string;
}

void Answer::setText(std::string textIn) {
	*text = textIn;
}

bool Answer::isCorrect()	{
	return this->correct;	
}

string Answer::getText() {
	return *text;
}

void Answer::setTrue()	{
	this->correct = true;
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


Question** Quiz::getQuestions() {
	return this->questions;
}

int Question::getCount()	{
	return this->noOfAnswers;
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