#ifndef __LOGIN__
#define __LOGIN__

#include "stdafx.h"
#include "User.h"
#include "SecurityControl.h"

#define CENTER_HEIGHT	(250)
#define CENTER_WIDTH	(400)
#define CENTER_MARGINS	(20)


using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

ref class LoginWindow : Panel {


public:
	LoginWindow(int, int, User**);

	
private:
	Panel^			container;
	
	Label^			mainLabel;
	
	Label^			usernameLabel;
	TextBox^		usernameBox;

	Label^			passwordLabel;
	MaskedTextBox^	passwordBox;

	Panel^			loginButtonPanel;
	Button^			loginButton;
	Drawing::Image^ loginButtonBack;

	User** mainUser;
	SecurityControl* loginController;

	void initializeComponents();	
	void resized(Object^, EventArgs^);
	void login (Object^, EventArgs^);
	void login (Object^, KeyEventArgs^);
};

#endif