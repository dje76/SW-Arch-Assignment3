#pragma once

/*
Consists of User and Admin functionality.
*/
class User {
public:
	string name;

	User();
	User(string name);
	void Login(Database db);
	void set_name(string n);
};

User::User(void) { }
User::User(string name) {	this->name = name; }

//setter
void User::set_name(string n) { this->name = n; }

