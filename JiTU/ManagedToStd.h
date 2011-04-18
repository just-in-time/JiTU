#ifndef __MANAGEDTOSTD__
#define __MANAGEDTOSTD__
#include <string>
#include "stdafx.h"

using namespace cli;
using namespace std;
using namespace System;

class ManagedToStd abstract {

public:

	static System::String^ toManaged(std::string in) {
	
		return gcnew String(in.c_str());

	}

	static std::string* toStd(String^ strIn) {
		string * returnValue;
		char * temp = new char[strIn->Length + 1];
	
		for (int i = 0; i < strIn->Length; i++)
			*(temp + i) = (char)strIn[i];
		
		*(temp + strIn->Length) = 0;
		returnValue = new string(temp);
		return returnValue;
	}


};

#endif