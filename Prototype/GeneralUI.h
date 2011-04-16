#ifndef __GENERALUI__
#define __GENERALUI__
#include "stdafx.h"
#include "LoginWindow.h"
#include "ContentWindow.h"
#include "User.h"
#include "Quiz.h"


#ifndef DEFAULT_HEIGHT
#define DEFAULT_HEIGHT (768)
#endif

#ifndef DEFAULT_WIDTH
#define DEFAULT_WIDTH (1024)
#endif

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;


ref class GeneralUI : System::Windows::Forms::Form {


public:
	GeneralUI();
	User** mainUser;

private:

	MenuStrip^ mainMenu;
	ToolStripMenuItem^ fileItem;
	ToolStripMenuItem^ exitItem;
	ToolStripMenuItem^ helpItem;
	ToolStripMenuItem^ aboutItem;
	ToolStripMenuItem^ logoutItem;

	LoginWindow^ login;
	ContentWindow^ content;


	void createMenu();
	void setIcon();

	void exitItemClicked (Object^ sender, EventArgs^ events);
	void logoutItemClicked (Object^ sender, EventArgs^ e);
	void loggedIn(Object^, EventArgs^);
	void enableLoginWindow();

};

#endif