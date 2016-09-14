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

	//db.print_all();
	cout << "Hello, welcome to the Online Shopping Center!" << endl;
	cout << "Enter (exit) if you would like to quit the program." << endl << endl;

	// log-loop
	while (strcmp(input, "exit") != 0) {

		cout << "Enter Your User Name : ";
		cin.getline(input, sizeof(input));

		if (db.search_user(input)) {
			user.set_name(input);
			user.get_cart();
			break;
		} else {
			cout << "Invalid User" << endl;
		}//end if/else
	}//end log-loop

	//operational loop
	while (strcmp(input, "exit") != 0) {
		cout << "\n----------\n" << "Main Menu\n" << "----------" << std::endl;
		cout << "Select an Option" << endl;
		cout << "1. browse" << endl;
		cout << "2. order history" << endl;
		cout << "3. view cart" << endl;
		cout << "4. remove" << endl;
		cout << "5. checkout" << endl;
		cout << "---------------" << endl;
		cout << "6. logout" << endl;
		cin.getline(input, sizeof(input));

//BROWSE
	if (!strcmp(input, "1") || !strcmp(input, "browse")) {
			std::cout << "\nSelect Catagory Number (1, 2...ect):" << std::endl;
			cout << "----------" << endl;
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
						std::cout << "\nPick an Item Number to add (or 'back') " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							db.household_table[index-1].print_details();
							std::cout << "Pick Quantity - (or 'back') " << std::endl;
							cin.getline(input, sizeof(input));
							if (!strcmp(input, "back")) { break; }
							int quantity = stoi(input);

							user.add_to_cart(db.household_table[index-1], quantity);
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
						std::cout << "\nPick an Item Number to add (or 'back') " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							db.toy_table[index-1].print_details();

							std::cout << "Pick Quantity - (or 'back') " << std::endl;
							cin.getline(input, sizeof(input));
							if (!strcmp(input, "back")) { break; }

							int quantity = stoi(input);
							user.add_to_cart(db.toy_table[index-1], quantity);
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
						std::cout << "\nPick an Item Number to add (or 'back') " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							db.electronic_table[index-1].print_details();

							std::cout << "Pick Quantity - (or 'back') " << std::endl;
							cin.getline(input, sizeof(input));
							if (!strcmp(input, "back")) { break; }

							int quantity = stoi(input);
							user.add_to_cart(db.electronic_table[index-1], quantity);
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
						std::cout << "\nPick an Item Number to add (or 'back') " << std::endl;
						cin.getline(input, sizeof(input));
						if (!strcmp(input, "back")) { break; }
						else {
							int index = stoi(input);
							db.book_table[index-1].print_details();

							std::cout << "Pick Quantity (or 'back') " << std::endl;
							cin.getline(input, sizeof(input));
							if (!strcmp(input, "back")) { break; }

							int quantity = stoi(input);
							user.add_to_cart(db.book_table[index-1], quantity);
							break;
						}//end if/else
					}//end true while
				}
		}//end browse

//ORDER HISTORY
		else if (!strcmp(input, "2") || !strcmp(input, "order history")) {
			user.view_history();
		}
//VIEW CART
		else if (!strcmp(input, "3") || !strcmp(input, "view order")) {
			std::cout << std::endl;
			std::cout << "----------\nYour Cart\n----------" << std::endl;
			std::cout << "Total: " <<user.cart.total << std::endl;
			for(int i=0;i<user.cart.items.size();i++){
				std::cout << i+1 << ".  "<< "Item name: " <<user.cart.items[i].name << std::endl;
				std::cout << "     Quantity: " <<user.cart.quantity[i] << std::endl;
			}
			cout <<endl;
		}

// REMOVE
	else if (!strcmp(input, "4") || !strcmp(input, "remove")){
		std::cout << "Choose an item to remove - or 'back'" << std::endl <<std::endl;

		//show current cart
		for(int i=0;i<user.cart.items.size();i++){
			std::cout << i+1 << ".  "<< "Item name: " <<user.cart.items[i].name << std::endl;
			std::cout << "     Quantity: " <<user.cart.quantity[i] << std::endl;
		}//end for loop

		while (true) {
			/*
			*/
			int cart_index;
			int quantity;
			std::cout << std::endl;
			cin.getline(input, sizeof(input));
			if (!strcmp(input, "back")) { break; }
			else {
				int cart_index = stoi(input);

				//helpful message :: "You have 'x' 'item_name' in your cart."
				std::cout << "You have "
									<< user.cart.quantity[cart_index-1]
									<< " '" << user.cart.items[cart_index-1].name << "'"
									<< " in your cart." << std::endl;

				std::cout << "How many do you want to Remove?" << std::endl;
				cin.getline(input, sizeof(input));
				int quantity = stoi(input);

				//call user method to remove item
				user.remove_from_cart(user.cart.items[cart_index-1], quantity);

				//helpful message :: "You now have 'x' 'item_name' in your cart."
				std::cout << "You now have "
									<< user.cart.quantity[cart_index-1]
									<< " '" << user.cart.items[cart_index-1].name << "'"
									<< " in your cart." << std::endl;
				break;
			}//end if/else
		}//end true while
	}//end if (remove)

//CHECKOUT
		else if (!strcmp(input, "5") || !strcmp(input, "checkout")) {

			//show cart
			std::cout << "----------\nYour Cart\n----------" << std::endl;
			std::cout << "Total: " <<user.cart.total << std::endl;
			for(int i=0;i<user.cart.items.size();i++){
				std::cout << i+1 << ".  "<< "Item name: " <<user.cart.items[i].name << std::endl;
				std::cout << "     Quantity: " <<user.cart.quantity[i] << std::endl;
			}//end for loop
			std::cout << "\nAre you sure you want to checkout? [yes/no]" << std::endl;
			cin.getline(input, sizeof(input));
			if (!strcmp(input, "yes")) {

				//get shipping address
				string address;
				std::cout << "Provide Shipping Information " << std::endl;
				cin.getline(input, sizeof(input));
				address = input;

				//get payment information
				string card_num;
				std::cout << "Provide Credit Cart Number " << std::endl;
				cin.getline(input, sizeof(input));
				card_num = input;

				//add information to the order
				user.update_address(address);
				user.update_payment(card_num);
				user.purchase_items();

				//            TODO
				//write the order to the data base

				std::cout << "You order was placed and your cart was cleared." << std::endl;
				std::cout << "Thank You!" << std:: endl << std::endl;
			} else {
				std::cout << "Order NOT confirmed. You may continue browsing." << std::endl;
			}//end if/else


		}//end if (checkout)

//LOGOUT
		else if (!strcmp(input, "6") || !strcmp(input, "logout")) {
			break;
		}

	}//end operational-loop

	std::cout << "Ending Program" << std::endl;

	return 0;
}
