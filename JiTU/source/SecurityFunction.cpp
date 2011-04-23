#include "SecurityFunction.h"

using namespace cli;
using namespace std;
using namespace System;
using namespace System::Security;
using namespace System::Security::Cryptography;


#pragma region Sha1

String^ security::Sha1(String^ strIn) {

	SHA1Managed^ working = gcnew SHA1Managed();
	String^ return_value = gcnew String("");
	array<unsigned char, 1>^ array1 = gcnew array<unsigned char, 1>(strIn->Length);

	for (int i = 0; i < strIn->Length; i++)
		array1[i] = (unsigned char)(strIn[i]);

	array1 = working->ComputeHash(array1);

	for (int i = 0; i < array1->Length; i++)
		for (int j = 0; j < (array1[i].ToString("X2"))->Length; j++)
			return_value = return_value + (array1[i].ToString("X2"))[j];
	

	return return_value;
}

#pragma endregion