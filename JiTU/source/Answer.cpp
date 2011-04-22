#include "Answer.h"

using namespace std;



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

