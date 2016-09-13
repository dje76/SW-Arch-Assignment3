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
	Database dbManager;
	vector<Order> orders;

	User();
	User(string name);
	void Login(Database db);
	void set_name(string n);
	vector<Order> view_history();
	void purchase_items();
	void update_address(string newAddress);
	void update_payment(string newPayment);
	void add_to_cart(Item item, int num);
	void remove_from_cart(Item item, int num);
};

User::User(void) { }
User::User(string name) {	this->name = name; }

//setter
void User::set_name(string n) { this->name = n; }

//stores the order in the database and empties the cart
void User::purchase_items(){
	dbManager.addOrderToDatabase(name, cart.items, cart.quantity, cart.total, address, payment);
	cart.clear();
}

void User::update_address(string newAddress){
	address = newAddress;
}

void User::update_payment(string newPayment){
	payment = newPayment;
}

void User::add_to_cart(Item item, int num){
	cart.addToCart(item, num);
}

void User::remove_from_cart(Item item, int num){
	cart.removeFromCart(item, num);
}

vector<Order> User::view_history(){
	vector< vector<string> >  dbOrders = dbManager.get_order_history(name);
	
	for(int i=0;i<dbOrders.size();i++){
		Order current_order;
		current_order.payment = dbOrders[i][0];
		current_order.address = dbOrders[i][1];
		current_order.total = std::stof(dbOrders[i][2]);
		for(int j=3;i<dbOrders.size();j+=3){
			Item current_item;
			current_item.name = dbOrders[i][j];
			current_item.price = std::stof(dbOrders[i][j+2]);
			current_order.quantity.push_back(std::stof(dbOrders[i][j+2]));
			current_order.items.push_back(current_item);
		}
		orders.push_back(current_order);
	}
	return orders;
}