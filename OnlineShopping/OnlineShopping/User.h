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
<<<<<<< HEAD
	void view_history();
=======
>>>>>>> 89de1e127a3a27a8676ad4a22a8b50cff5ceb4b4
	void purchase_items();
	void updateAddress(string newAddress);
	void updatePayment(string newPayment);
	void addToCart(Item item, int num);
	void removeFromCart(Item item, int num);
};

User::User(void) {
	dbManager.set_directory("Files");
}
User::User(string name) {	this->name = name; dbManager.set_directory("Files");}

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
<<<<<<< HEAD

void User::view_history(){
	cout << endl;
	vector< vector<string> >  dbOrders = dbManager.get_order_history(name);
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
=======
>>>>>>> 89de1e127a3a27a8676ad4a22a8b50cff5ceb4b4
