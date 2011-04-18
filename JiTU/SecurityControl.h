#ifndef __SECURITYCONTROL__
#define __SECURITYCONTROL__
#include <string>
#include "stdafx.h"
#include "User.h"


using namespace std;
using namespace System;
using namespace System::Security;
using namespace System::Security::Cryptography;


class SecurityControl {

public:
	SecurityControl(User**);

	bool checkUsername(String^);
	bool checkPassword(String^);


private:
	
	User** mainUser;


};
#endif