#pragma once

/*
Consists of User and Admin functionality.
*/
class User {
public:
	string name;
	Cart cart;
	string payment;
	string address;
	//Database dbManager;

	User();
	User(string name);
	void Login(Database db);
	void set_name(string n);
	void purchase_items();
	void updateAddress(string newAddress);
	void updatePayment(string newPayment);
	void addToCart(Item item, int num);
	void removeFromCart(Item item, int num);
};

User::User(void) { }
User::User(string name) {	this->name = name; }

//setter
void User::set_name(string n) { this->name = n; }

//stores the order in the database and empties the cart
void User::purchase_items(){
	//dbManager.addOrderToDatabase(name, cart.items, cart.quantity, cart.total, address, payment);
	cart.clear();
}

void User::updateAddress(string newAddress){
	address = newAddress;
}

void User::updatePayment(string newPayment){
	payment = newPayment;
}

void User::addToCart(Item item, int num){
	cart.addToCart(item, num);
}

void User::removeFromCart(Item item, int num){
	cart.removeFromCart(item, num);
}
