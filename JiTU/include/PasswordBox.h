#ifndef __PASSWORDBOX__
#define __PASSWORDBOX__
#include "stdafx.h"
#include "SecurityFunction.h"

using namespace security;
using namespace cli;
using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;

ref class PasswordBox : MaskedTextBox {

public:

	PasswordBox();

	property String^ Password {
		String^ get();
	}

private:
	property String^ maskedText;
	void onCharEntered(Object^, EventArgs^);

};
#endif