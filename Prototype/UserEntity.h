#pragma once
#include "entityBase.h"
using namespace System;

ref class UserEntity : entityBase
{
public:
	UserEntity(void);
	void AddUser(User *);
	void UpdateUser(User *);
	void DeleteUser(User *);
	User * GetUser(String^);
};