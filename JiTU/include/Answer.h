#ifndef __ANSWER__
#define __ANSWER__
#include <iostream>
#include <string.h>
#include "stdafx.h"

using namespace std;

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

#endif