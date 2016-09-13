#pragma once

/*
Consists of User and Admin functionality.
*/
class User {
public:
	string name;
	Order order;

	User();
	User(string name);
	void Login(Database db);
	void set_name(string n);
	void purchase_items();
	void cancel_order();
	void updateAddress(string newAddress);
	void updatePayment(string newPayment);
	void addToCart(Item item, int num);
	void removeFromCart(Item item, int num);
};

User::User(void) { }
User::User(string name) {	this->name = name; }

//setter
void User::set_name(string n) { this->name = n; }

void User::purchase_items(){
	order.Confirm(name);
}

void User::cancel_order(){
	order.Cancel();
}

void User::updateAddress(string newAddress){
	order.updateAddress(newAddress);
}

void User::updatePayment(string newPayment){
	order.updatePayment(newPayment);
}

void User::addToCart(Item item, int num){
	order.addToCart(item, num);
}

void User::removeFromCart(Item item, int num){
	order.removeFromCart(item, num);
}
