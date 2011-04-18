#include "SecurityControl.h"
#include "ManagedToStd.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace System;
using namespace System::Security;
using namespace System::Security::Cryptography;


SecurityControl::SecurityControl(User ** userIn) {
	mainUser = userIn;
}

bool SecurityControl::checkPassword(String^ passwordIn) {
	
	bool returnValue = false;
	
	if (*mainUser) 
		if (!((*mainUser)->getPassword()).compare(*(ManagedToStd::toStd(passwordIn))))
			returnValue = true;

	return returnValue;
}

bool SecurityControl::checkUsername(String^ user) {

	*mainUser = new User(0);

	(*mainUser)->setUsername(*(ManagedToStd::toStd(user)));

	if (!((*mainUser)->getUsername()).compare("student")) {
		(*mainUser)->setRole(1);
		(*mainUser)->setPassword("student");
	}
	else if (!((*mainUser)->getUsername()).compare("teacher")) {
		(*mainUser)->setRole(0);
		(*mainUser)->setPassword("teacher");
	}
	else {
		delete (*mainUser);
		*mainUser = NULL;
	}	
	
	return ((*mainUser) != NULL);
}