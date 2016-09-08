#pragma once

/*
Consists of User and Admin functionality.
*/
class User {
public:
	string name;

	User();
	User(string name);
	void Login();
};

User::User(void) {}

User::User(string name) {
	this->name = name;
}

void User::Login(void) {
	char input[100];


	while (strcmp(input, "logout") != 0) {
		cout << "Welcome, " << this->name << "!" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. nothing" << endl;
		cout << "2. nothing here either" << endl;
		cout << "3. logout" << endl;


		cin.getline(input, sizeof(input));

	}
	


}



class Admin : public User {
public:
	string password;

	Admin(string name, string password);

	void Login();
};

Admin::Admin(string name, string password) {
	this->name = name;
	this->password = password;
}

void Admin::Login(void) {}