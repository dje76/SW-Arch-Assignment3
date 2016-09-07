#pragma once

/*
Consists of User and Admin functionality.
*/
class User {
public:
	string name;

	User();
	User(string name);
};

User::User(void) {}

User::User(string name) {
	this->name = name;
}




class Admin : public User {
public:
	string password;

	Admin(string name, string password);
};

Admin::Admin(string name, string password) {
	this->name = name;
	this->password = password;
}