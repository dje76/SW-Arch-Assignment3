#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "Functions.h"
#include "Items.h"
#include "Cart.h"
#include "DatabaseManager.h"
#include "User.h"


int main() {
	// Generate the database from the text file.
	Database db("Files");
	char input[100];
	User user;

	cout << "Hello, welcome to the Online Shopping Center!" << endl;
	cout << "Enter (exit) if you would like to quit the program." << endl;

	// log-loop
	while (strcmp(input, "exit") != 0) {

		cout << "Enter Your User Name :: ";
		cin.getline(input, sizeof(input));

		if (db.search_user(input)) {
			user.set_name(input);
			break;
		} else {
			cout << "Invalid User" << endl;
		}//end if/else
	}//end log-loop

	//operational loop
	while (strcmp(input, "exit") != 0) {
		cout << "Select an Option" << endl;
		cout << "1. browse" << endl;
		cout << "2. search" << endl;
		cout << "3. logout" << endl;
		cin.getline(input, sizeof(input));

//BROWSE
		if (!strcmp(input, "1") || !strcmp(input, "browse")) {
			//std::cout << "option 1 : brose" << std::endl;
			db.print_all();
		}

//SEARCH
		if (!strcmp(input, "2") || !strcmp(input, "search")) {
			
		}

//LOGOUT
		if (!strcmp(input, "3") || !strcmp(input, "logout")) {
			break;
		}




	}//end operational-loop

	std::cout << "Out of the looop" << std::endl;


	/*


	while (strcmp(input, "exit") != 0) {
		cout << "Please enter your pre-registered username: ";
		cin.getline(input, sizeof(input));
		cout << endl;

		if (db.search_user(input)) {
			User user(input);
			user.Login(db);
		}
		else {
			cout << "Invalid Account" << endl;
		}
	}
	*/

	return 0;
}

