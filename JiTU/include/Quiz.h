#ifndef __QUIZ__
#define __QUIZ__
#include <string>
#include "Question.h"

using namespace std;

class Quiz {
public:
	Quiz		(int id);
	int			getCount	();
	Question**	getQuestions();
	void		addQuestion	(Question * question);
	void		setTitle(string);
	string		getTitle();


private:
	int			id;
	int			noOfQuestions;
	string*		title;
	Question**	questions;

};


#endif
