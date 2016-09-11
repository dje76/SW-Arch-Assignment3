#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "Functions.h"
#include "Items.h"
#include "User.h"
#include "Cart.h"
#include "DatabaseManager.h"

int main() {
	// Generate the database from the text file.
	Database db("Files");

	char input[100];

	cout << "Hello, welcome to the Online Shopping Center!" << endl;
	cout << "Enter (exit) if you would like to quit the program." << endl;

	while (strcmp(input, "exit") != 0) {
		cout << endl << "Please enter your pre-registered username: ";
		cin.getline(input, sizeof(input));

		cout << db.search_user(input) << endl; // It works!
		
		if (db.search_user(input)) {
			User user(input);
			user.Login();
		}
		else {
			cout << "Invalid Account" << endl << endl;
		}
		// TODO:
		// If the user exists, call user methods.

	}

	




	return 0;
}

