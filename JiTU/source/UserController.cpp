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

	userEntity = gcnew UserEntity(); //creates our user entity to be used
									 // in this controller

	*user = new User(0); //create an instance of User


}


void UserController::authenticateUser(String^ userName, String^ password)
{
	/* get user and check username*/
	try
	{
		*user = userEntity->GetUser(userName);
	}
	catch (MySqlException^ e)
	{
	    delete *user;
		*user = NULL;
		throw gcnew System::Exception(e->Message, e->InnerException);
	}

	/* check passwords match */
	if ( password->CompareTo( ManagedToStd::toManaged( (*user)->getPassword() ) ) )
	{
		//they dont match
		delete *user;
		*user = NULL;
		throw gcnew System::Exception(gcnew String("The passwords do not match"));
	}
}
