#ifndef __ACTIVITYMENU__
#define __ACTIVITYMENU__
#include "User.h"
#include "stdafx.h"
#include "StudentContent.h"
#include "InstructorContent.h"


using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;



ref class ActivityMenu : Panel {

public:
	ActivityMenu(User** userIn, Panel^ contentIn) : Panel() {
		mainUser	= userIn;
		Dock		= DockStyle::Fill;
		mainPanel	= contentIn;
		Padding		= Forms::Padding(0, 25, 0, 0);
		mainPanel->Padding = Forms::Padding(0, 25, 0, 0);
		BackColor	= Color::FromArgb(0xffcf6c4e);
		buttonBack	= Drawing::Image::FromFile(gcnew String("button_back.png"));
		buttonFont	= gcnew Drawing::Font("Lucida Console", 16 , FontStyle::Bold, GraphicsUnit::Pixel);

		
	}

protected:
	Panel^			mainPanel;
	User**			mainUser;
	Image^			buttonBack;
	Drawing::Font^	buttonFont;

};


#endif