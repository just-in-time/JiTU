#include "UserController.h"
#include "ManagedToStd.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace System;
using namespace MySql::Data::MySqlClient;

UserController::UserController(User ** userIn)
{

	
	user = userIn; //assigns user pointer to external user pointer(from GeneralUI)
	/**
	userEntity = gcnew UserEntity(); //creates our user entity to be used
									 // in this controller

	**/

	*user = new User(0);
	(*user)->setRole(0);


}

bool UserController::isValidUser(System::String ^userName)
{
	/**
	try
	{
		
		*user = userEntity->GetUser(userName);
	}
	catch (MySqlException^ e)
	{
		*user = NULL;
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	**/
	

	return (*user != NULL);
}
