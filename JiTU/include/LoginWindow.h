#ifndef __LOGIN__
#define __LOGIN__

#include "stdafx.h"
#include "User.h"
#include "UserController.h"

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
	/**
	 *	Constructor for class, initializes all controls placed on
	 *	the LoginWindow Panel
     *
	 *	@param xIn The width of the window
	 *	@param yIn The height of the window
	 *	@param userIn Pointer to user object to be loged in 
	 */
	LoginWindow(int xIn, int yIn, User** userIn);
	
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
	UserController^ userController;

	void initializeComponents();	
	void resized(Object^, EventArgs^);
	void login (Object^, EventArgs^);
	void login (Object^, KeyEventArgs^);
	void login (); //gets called by other logins
};

#endif