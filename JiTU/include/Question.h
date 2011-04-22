#ifndef __QUESTION__
#define __QUESTION__
#include <iostream>
#include <string>
#include "Answer.h"

using namespace std;

class Question {
public:
	Question	(int);
	void		addAnswer	(Answer *);
	void		setText		(string);
	Answer**	getAnswers	();
	int			getCount	();
	string		getText		();

private:
	int			id;
	string*		text;
	Answer**	answers;
	int			noOfAnswers;

};


#endif