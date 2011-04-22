#ifndef __CONTENTWINDOW__
#define __CONTENTWINDOW__
#include "User.h"
#include "stdafx.h"
#include "StudentContent.h"
#include "InstructorContent.h"
#include "ActivityMenu.h"
#include "StudentMenu.h"
#include "InstructorMenu.h"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;


ref class ContentWindow : SplitContainer {

public:
	ContentWindow(User** userIn) : SplitContainer() {

		mainUser = userIn;
		Dock = DockStyle::Fill;
		SplitterDistance = 25;

		Panel1->BackColor = Color::FromArgb(0xffe9a05b);

		if (!(*mainUser)->getRole())
			nav = gcnew InstructorMenu(userIn, Panel2);
		else
			nav = gcnew StudentMenu(userIn, Panel2);

		this->IsSplitterFixed = true;
		Panel1->Controls->Add(nav);
		Panel1->BorderStyle = Forms::BorderStyle::FixedSingle;
		BorderStyle = Forms::BorderStyle::None;

	}

private:
	User**			mainUser;
	ActivityMenu^	nav;
	Image^			panelBack;

};




#endif