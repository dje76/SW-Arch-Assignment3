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
	
	cout << "Welcome, " << this->name << "!" << endl;
	while (1) {
		cout << "Options:" << endl;
		cout << "1. nothing" << endl;
		cout << "2. nothing here either" << endl;
		cout << "3. logout" << endl;

		cout << this->name << ": ";
		cin.getline(input, sizeof(input));



		// Exit the while loop.
		if (!strcmp(input, "logout") || !strcmp(input, "3")) {
			break;
		}


		cout << endl;
	}
	


}