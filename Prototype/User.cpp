#include <string>
#include "User.h"

using namespace std;

User::User(int id) {
	this->id = id;
	this->username = new string;
	this->password = new string;
	this->role = 0;
	this->classes = new Course*;
	*(this->classes) = 0;
	this->classCount = 0;
}


void User::setUsername(std::string newUsername) {
	*(this->username) = newUsername; 
}

void User::setPassword(std::string newPassword) {
	*(this->password) = newPassword;
}

string User::getUsername() {
	return *(this->username);
}

string User::getPassword() {
	return *(this->password);
}

void User::setRole(int roleIn) {
	role = roleIn;
}

int User::getRole() {
	return role;
}

void User::addClass(Course * classIn) {
	Course** temp = classes;
	classes = new Course*[classCount + 1];
	for (int i = 0; i < classCount; i++) {
		*(classes + i) = *(temp + i);
	}
	*(classes + classCount) = classIn;
	delete temp;
	classCount++;
}


Course** User::getClasses() {

	return classes;
}

int User::getClassCount() {
	return classCount;
}