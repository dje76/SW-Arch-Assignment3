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
};

User::User(void) {}

User::User(string name) {
	this->name = name;
}

void User::Login(Database db) {
	char input[100];
	
	cout << "Welcome, " << this->name << "!" << endl;
	while (1) {
		cout << "Options:" << endl;
		cout << "1. browse" << endl;
		cout << "2. search" << endl;
		cout << "3. logout" << endl;

		cout << this->name << ": ";
		cin.getline(input, sizeof(input));

		if (!strcmp(input, "1") || !strcmp(input, "browse")) {
			db.print_all();
		}

		// Call search functionality
		if (!strcmp(input, "2") || !strcmp(input, "search")) {
			cout << "What would you like to search for?" << endl;
			cout << this->name << ": ";
			cin.getline(input, sizeof(input));
			db.search_item(input);
		}

		// Exit the while loop.
		if (!strcmp(input, "3") || !strcmp(input, "logout")) {
			break;
		}


		cout << endl;
	}
	


}