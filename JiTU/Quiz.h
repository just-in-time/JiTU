#ifndef __QUIZ__
#define __QUIZ__
#include <string>

using namespace std;

/************************************************************************************************
************************************************************************************************/

class Answer {
public:
	Answer		(int id);
	string		getText		();
	bool		isCorrect	();
	void		setText		(string);
	void		setTrue		();

private:
	int			id;
	string*		text;
	bool		correct;

};

/************************************************************************************************
************************************************************************************************/

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

/************************************************************************************************
************************************************************************************************/

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

/************************************************************************************************
************************************************************************************************/

#endif
