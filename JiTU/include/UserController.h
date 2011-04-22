#pragma once
#include <string>
#include "stdafx.h"
#include "User.h"
#include "UserEntity.h"


using namespace std;
using namespace System;

ref class UserController
{
public:
	/**
	 *	Constructor for UserController
	 *
	 *  @param userIn the user to be associated with this controller
	 */
	UserController(User** userIn);
	
	/**
	 *	Retrieves user data from the user entity
     *
	 *	@param userName name to search for
	 *  @param password password to check for
	 *	@throw Exception the username not found or password is invalid
	 */
	void authenticateUser(String^ userName, String^ password);


private:
	
	User** user;
	UserEntity^ userEntity;
};
