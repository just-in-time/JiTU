#ifndef __ANSWER__
#define __ANSWER__
#include <iostream>
#include <string.h>
#include "stdafx.h"

using namespace std;

/**
*	Class Answer:
*	
*	Implements floating data throughout program
*
*	----	DataMembers		----
*	id			- Identification, Unique
*	text		- The text of the answer
*	correct		- whether or not this answer is correct
*
*	----	Functions		----
*	getText		- get the internal text of the answer
*	isCorrect	- return if the correct answer
*	setText		- set the internal text of the answer
*	setTrue		- set to be the correct answer
*	
*/

class Answer {

public:

	/**ctor**/	Answer		(int id);
	string		getText		();
	bool		isCorrect	();
	void		setText		(string);
	void		setTrue		();

private:

	int			id;
	string*		text;
	bool		correct;

};

#endif