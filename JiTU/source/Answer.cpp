#include "Answer.h"

using namespace std;

#pragma region Answer_ctor

Answer::Answer	(int idIn) 	{

		// Set all values to zero for default;

	this->id 		= idIn;
	this->correct 	= false;
	this->text 		= new string;
	
}

#pragma endregion

#pragma region Answer_Set_Text

void Answer::setText (string textIn) {

	*text = textIn;

}

#pragma endregion

#pragma region Answer_is_Correct

bool Answer::isCorrect()	{

	return correct;	
}

#pragma endregion

#pragma region Answer_get_Text

string Answer::getText() {

	return *text;

}

#pragma endregion

#pragma region Answer_set_True

void Answer::setTrue()	{

	this->correct = true;

}

#pragma endregion
