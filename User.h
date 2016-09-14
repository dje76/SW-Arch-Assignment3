#pragma once

/*
The user class is what the main class interacts with.
The main class does not interact with any other classes but does everything though the user class.

The main class has a dependency on the user class.
User has a dependency on the cart class.
*/
class User {
public:
	string name;
	Cart cart;
	string payment;
	string address;
	vector<Order> orders;

	User();
	User(string name);
	void Login(Database db);
	void set_name(string n);
	void get_cart();
	void view_history();
	void purchase_items();
	void update_address(string newAddress);
	void update_payment(string newPayment);
	void add_to_cart(Item item, int num);
	void remove_from_cart(Item item, int num);
};

User::User(void) {}
User::User(string name) { this->name = name; }

//setter
void User::set_name(string n) { this->name = n; }

void User::get_cart(){ cart.set_cart(name); }

//stores the order in the database and empties the cart
void User::purchase_items(){
	cart.dbManager.addOrderToDatabase(name, cart.items, cart.quantity, cart.total, address, payment);
	for (int i = 0; i < cart.items.size(); i++) {

		for(int j=0;j<cart.dbManager.household_table.size();j++){
			if(cart.items[i].name == cart.dbManager.household_table[j].name){
			cart.dbManager.household_table[j].quantity -= cart.quantity[i];
			}
		}

		for(int j=0;j<cart.dbManager.book_table.size();j++){
			if(cart.items[i].name == cart.dbManager.book_table[j].name){
			cart.dbManager.book_table[j].quantity -= cart.quantity[i];
			}
		}

		for(int j=0;j<cart.dbManager.electronic_table.size();j++){
			if(cart.items[i].name == cart.dbManager.electronic_table[j].name){
			cart.dbManager.electronic_table[j].quantity -= cart.quantity[i];
			}
		}

		for(int j=0;j<cart.dbManager.toy_table.size();j++){
			if(cart.items[i].name == cart.dbManager.toy_table[j].name){
			cart.dbManager.toy_table[j].quantity -= cart.quantity[i];
			}
		}

	}//end for loop
	cart.clear(name);
}//end purchase_items()

void User::update_address(string newAddress){
	address = newAddress;
}

void User::update_payment(string newPayment){
	payment = newPayment;
}

void User::add_to_cart(Item item, int num){
	cart.addToCart(item, num, name);
}

void User::remove_from_cart(Item item, int num){
	cart.removeFromCart(item, num, name);
}

void User::view_history(){
	cout << endl;
	orders.clear();
	vector< vector<string> >  dbOrders = cart.dbManager.get_order_history(name);
	if(dbOrders[0].size()==0 || dbOrders[0].size()==1){
		cout << "You have no previous orders" << endl;
		cout << endl;
		return;
	}
	cout << "Name: " << name << endl;
	for(unsigned int i=0;i<dbOrders.size();i++){
		Order current_order;
		current_order.payment = dbOrders[i][0];
		cout << "Payment: " << dbOrders[i][0] << endl;
		current_order.address = dbOrders[i][1];
		cout << "Address: " << dbOrders[i][1] << endl;
		current_order.total = std::stof(dbOrders[i][2]);
		cout << "Total: " << dbOrders[i][2] << endl;
		for(unsigned int j=3;j<dbOrders[i].size();j+=3){
			Item current_item;
			current_item.name = dbOrders[i][j];
			cout << "Item name: " << dbOrders[i][j] << endl;
			current_order.quantity.push_back(std::stoi(dbOrders[i][j+1]));
			cout << "Item quantity: " << dbOrders[i][j+1] << endl;
			current_item.price = std::stof(dbOrders[i][j+2]);
			cout << "Item price: " << dbOrders[i][j+2] << endl;
			current_order.items.push_back(current_item);
		}
		orders.push_back(current_order);
		cout << endl;
		cout << endl;
	}
}
