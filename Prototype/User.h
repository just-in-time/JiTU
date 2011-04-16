#ifndef __USER__
#define __USER__
#include <string>
#include "Course.h"

using namespace std;

/************************************************************************************************
************************************************************************************************/

class User {

public:

	/*ctor*/	User		(int id);

	/** Setters **/
	void		setUsername		(string);
	void		setPassword		(string);
	void		setRole			(int);
	void		addClass		(Course*);

	/** Getters **/
	string		getUsername		();
	string		getPassword		();
	int			getRole			();
	Course**	getClasses		();
	int			getClassCount	();
	
private:

	/** Data Members **/
	int			id;
	int			role;
	int			classCount;
	string*		username;
	string*		password;
	Course**	classes;	

};

/************************************************************************************************
************************************************************************************************/

#endif