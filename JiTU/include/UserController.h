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
	UserController(User** userIn);

	bool isValidUser(String^ userName);


private:
	
	User** user;
	UserEntity^ userEntity;
};
