#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "Functions.h"
#include "Items.h"
#include "DatabaseManager.h"
#include "Cart.h"
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
		cout << "2. order history" << endl;
		cout << "3. logout" << endl;
		cin.getline(input, sizeof(input));

//BROWSE
	if (!strcmp(input, "1") || !strcmp(input, "browse")) {
			std::cout << "\nSelect Catagory:" << std::endl;
			cout << "1. Household" << endl;
			cout << "2. Toys" << endl;
			cout << "3. Electronics" << endl;
			cout << "4. Books" << endl << endl;
			cin.getline(input, sizeof(input));

				//print househould items
				if (!strcmp(input, "1")) {
					std::cout << "Household" << std::endl << "-------------" << endl;
					for (int i = 0; i < db.household_table.size(); i++) {
						std::cout << i+1 << ". " << db.household_table[i].name << std::endl;
					}//end for loop
					while (true) {
						int item;
						int quantity;
						std::cout << "Pick an Item Number to add - or back " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							std::cout << "Pick Quantity " << std::endl;
							cin.getline(input, sizeof(input));
							int quantity = stoi(input);

							user.cart.addToCart(db.household_table[index-1], quantity);
							break;

						}//end if/else
					}//end true while


				}

				//print toy items
				else if (!strcmp(input, "2")) {
					std::cout << "Toys" << std::endl << "-------------" << endl;
					for (int i = 0; i < db.toy_table.size(); i++) {
						std::cout << i+1 << ". " << db.toy_table[i].name << std::endl;
					}//end for loop
					while (true) {
						int item;
						int quantity;
						std::cout << "Pick an Item Number to add - or back " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							std::cout << "Pick Quantity " << std::endl;
							cin.getline(input, sizeof(input));
							int quantity = stoi(input);
							user.cart.addToCart(db.toy_table[index-1], quantity);
							break;
						}//end if/else
					}//end true while
				}

				//print electric items
				else if (!strcmp(input, "3")) {
					std::cout << "Electronics" << std::endl << "-------------" << endl;
					for (int i = 0; i < db.electronic_table.size(); i++) {
						std::cout << i+1 << ". " << db.electronic_table[i].name << std::endl;
					}//end for loop
					while (true) {
						int item;
						int quantity;
						std::cout << "Pick an Item Number to add - or back " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							std::cout << "Pick Quantity " << std::endl;
							cin.getline(input, sizeof(input));
							int quantity = stoi(input);
							user.cart.addToCart(db.electronic_table[index-1], quantity);
							break;
						}//end if/else
					}//end true while
				}

				//print book items
				else if (!strcmp(input, "4")) {
					std::cout << "Books" << std::endl << "-------------" << endl;
					for (int i = 0; i < db.book_table.size(); i++) {
						std::cout << i+1 << ". " << db.book_table[i].name << std::endl;
					}//end for loop
					while (true) {
						int item;
						int quantity;
						std::cout << "Pick an Item Number to add - or back " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							std::cout << "Pick Quantity " << std::endl;
							cin.getline(input, sizeof(input));
							int quantity = stoi(input);
							user.cart.addToCart(db.book_table[index-1], quantity);
							break;
						}//end if/else
					}//end true while
				}
		}//end browse

//ORDER HISTORY
		else if (!strcmp(input, "2") || !strcmp(input, "order history")) {
			user.view_history();
		}
//LOGOUT
		else if (!strcmp(input, "3") || !strcmp(input, "logout")) {
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
