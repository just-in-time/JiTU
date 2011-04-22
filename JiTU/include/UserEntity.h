#pragma once
#include "entityBase.h"
#include "User.h"
using namespace System;

ref class UserEntity : entityBase
{
public:
	/**
	 *	Constructor for UserEntity
     *
	 */
	UserEntity(void);

	void AddUser(User *);
	void UpdateUser(User *);
	void DeleteUser(User *);

	/**
	 *	Gets a returns a user from the data base with the specified string.
	 *  Throws an ex
     *
	 *	@param user name to search for
	 *	@throw Exception the username not found
	 */
	User * GetUser(String^);
	User * GetUser(int);
};
