#include "LoginWindow.h"

using namespace cli;
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;


LoginWindow::LoginWindow(int xIn, int yIn, User** userIn)	: Panel()	{

	SuspendLayout();
	initializeComponents();

	Dock = DockStyle::Fill;

	mainUser = userIn;

	container->Height = CENTER_HEIGHT;
	container->Width = CENTER_WIDTH;
	container->Location = Point((xIn - CENTER_WIDTH) / 2, (yIn - CENTER_HEIGHT - 25) / 2);

	mainLabel->Text = gcnew String("JiTU");
	mainLabel->Font = gcnew Drawing::Font("Lucida Handwriting", 36, FontStyle::Bold, GraphicsUnit::Pixel);
	mainLabel->Height = 50;
	mainLabel->Width = 150;
	mainLabel->TextAlign = Drawing::ContentAlignment::MiddleCenter;
	mainLabel->Location = Point((CENTER_WIDTH - 150) / 2, 20);

	usernameLabel->Text = gcnew String("Username");
	passwordLabel->Text = gcnew String("Password");

	Drawing::Font^ temp = gcnew Drawing::Font("Lucida Console", 14, FontStyle::Bold, GraphicsUnit::Pixel);

	usernameLabel->Font = temp;
	passwordLabel->Font = temp;

	usernameLabel->Location = Point(CENTER_MARGINS, 98);
	passwordLabel->Location = Point(CENTER_MARGINS, 134);

	usernameBox->Width = 250;
	passwordBox->Width = 250;

	usernameBox->Height = 16;
	passwordBox->Height = 16;

	usernameBox->Location = Point((CENTER_WIDTH - usernameBox->Width - CENTER_MARGINS), 96);
	passwordBox->Location = Point((CENTER_WIDTH - passwordBox->Width - CENTER_MARGINS), 132);

	loginButtonPanel->Height = 50;
	loginButtonPanel->Width  = CENTER_WIDTH - (2 * CENTER_MARGINS);
	loginButtonPanel->Location = Point(CENTER_MARGINS, (CENTER_HEIGHT - loginButtonPanel->Height - CENTER_MARGINS));
	
	loginButton->Dock = DockStyle::Fill;
	loginButton->Text = gcnew String("Login");
	loginButton->BackgroundImage = loginButtonBack;
	loginButton->ForeColor = Color::Black;

	loginButton->FlatStyle = FlatStyle::Popup;

	loginButton->Font = gcnew Drawing::Font("Lucida Console", 16, FontStyle::Bold, GraphicsUnit::Pixel);

	passwordBox->PasswordChar = '*';

	Controls->Add(container);

	container->Controls->AddRange(gcnew array<Control^>(6) {
		mainLabel,
		usernameLabel,
		usernameBox,
		passwordLabel,
		passwordBox,
		loginButtonPanel
	});

	loginButtonPanel->Controls->Add(loginButton);
	BackColor = Color::DarkGray;

	container->BackColor = Color::LightGray;
	container->BorderStyle = Forms::BorderStyle::FixedSingle;

	this->Resize += gcnew EventHandler(this, &LoginWindow::resized);
	ResumeLayout();
}


void LoginWindow::initializeComponents() {
	
	container = gcnew Panel();
	loginButtonPanel = gcnew Panel();
	loginButton = gcnew Button();
	usernameBox = gcnew TextBox();
	passwordBox = gcnew MaskedTextBox();
	usernameLabel = gcnew Label();
	passwordLabel = gcnew Label();
	mainLabel = gcnew Label();
	loginButtonBack = Drawing::Image::FromFile(gcnew String("login_back.png"));
	loginButton->Click += gcnew EventHandler(this, &LoginWindow::login);
	passwordBox->KeyDown += gcnew KeyEventHandler(this, &LoginWindow::login);

}

void LoginWindow::resized (Object^ sender, EventArgs^ e)	{
	
	container->Location = Point((Width - container->Width) / 2, (Height - container->Height) /2);
	
}

void LoginWindow::login(System::Object ^, System::EventArgs ^) {
	login();
}

void LoginWindow::login(System::Object ^ se, System::Windows::Forms::KeyEventArgs ^ e) {
	if (e->KeyCode == Keys::Enter) {
		login();
	}
}

void LoginWindow::login() {
	/* OLD CODE
	loginController = new SecurityControl(mainUser);
	if (loginController->checkUsername(usernameBox->Text))
		if (loginController->checkPassword(passwordBox->Text))
			delete this;
	*/
	
	try {

	userController = gcnew UserController(mainUser);
	userController->isValidUser(usernameBox->Text);
	delete this;

	} catch(Exception^ e) {
		  // Create a new instance of the form.
		  Form^ form1 = gcnew Form;
		  // Create two buttons to use as the accept and cancel buttons.
		  Button^ button1 = gcnew Button;
		  Button^ button2 = gcnew Button;

		  form1->SuspendLayout();

		  Label^ mainMessage = gcnew Label();
		  mainMessage->Text = e->Message;
		  
		  form1->Controls->Add(mainMessage);
		  mainMessage->Anchor = Forms::AnchorStyles::None;
		  mainMessage->Padding = Forms::Padding(20);
		  mainMessage->AutoSize = true;

		  // Set the text of button1 to "OK".
		  button1->Text = "OK";
		  // Set the position of the button on the form.
		  button1->Location = Point((form1->Width - 2 * (button1->Width + 40)),(form1->Height - (button1->Height + 40)));
		  // Set the text of button2 to "Cancel".
		  button2->Text = "Cancel";
		  // Set the position of the button based on the location of button1.
		  button2->Location =
			  Point( button1->Location.X + 20 + button1->Width, button1->Location.Y);
		  // Set the caption bar text of the form.   
		  form1->Text = "Error";
		  // Display a help button on the form.

		  // Define the border style of the form to a dialog box.
		  form1->FormBorderStyle = ::FormBorderStyle::FixedDialog;
		  // Set the MaximizeBox to false to remove the maximize box.
		  form1->MaximizeBox = false;      
		  // Set the MinimizeBox to false to remove the minimize box.
		  form1->MinimizeBox = false;
		  // Set the accept button of the form to button1.
		  form1->AcceptButton = button1;

		  form1->CancelButton = button1;
		  // Set the cancel button of the form to button2.
		  // Set the start position of the form to the center of the screen.
		  form1->StartPosition = FormStartPosition::CenterScreen;
		  form1->ResumeLayout();
		  // Add button1 to the form.
		  form1->Controls->Add( button1 );
		  // Add button2 to the form.
		  form1->Controls->Add( button2 );
		  // Display the form as a modal dialog box.
		  form1->ShowDialog();

	};
	
	
}