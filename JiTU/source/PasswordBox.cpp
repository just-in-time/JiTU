#include "PasswordBox.h"


PasswordBox::PasswordBox() : MaskedTextBox() {
	PasswordChar = (wchar_t)('*');
	maskedText = gcnew String("");
	maskedText = Sha1(Text);
	this->TextChanged += gcnew EventHandler(this, &PasswordBox::onCharEntered);
	
}

String^ PasswordBox::Password::get() {
	return this->maskedText;
}

void PasswordBox::onCharEntered(Object ^sender ,EventArgs^ e) {
	maskedText = Sha1(Text);
}
