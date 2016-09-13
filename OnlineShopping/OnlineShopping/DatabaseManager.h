#pragma once

/*
Database consisting of two tables: Users and Items.
Requires text files to pull data from.
Will overwrite the text files upon completion to update information.
*/

class Database {
public:
	string directory;
	vector <string> user_table;
	vector <Item> item_table;
	
	vector <Item> items_in_cart;
	vector <int> quantity;
	
	Database(void);
	Database(string filename);
	void set_directory(string directory);
	vector<string> tokenize(const string &line);
	void insert_user(string user);
	void insert_item(Item item);

	string generate_user(vector <string> values);
	Item generate_item(vector <string> values);
	Household generate_household(vector<string> values);
	Book generate_book(vector<string> values);
	Toy generate_toy(vector<string> values);
	Electronic generate_electronic(vector<string> values);

	vector< vector<string> > get_order_history(string user);
	bool search_user(string value);
	void search_item(string value);
	void print(string type);
	void print_all();
	void updateCartInDatabase(vector<Item> items,vector<int> quantity);
	void addOrderToDatabase(string user, vector<Item> items,vector<int> quantity,float total,string address,string payment);
	void getCartFromDatabase(vector<Item> &items,vector<int> &quantity);
};

Database::Database(void){}

Database::Database(string directory) {
	this->directory = directory;
	// Input file that stores usernames
	ifstream userInfile(directory + "/users.txt");
	// Input file that stores item data in comma separated format.
	ifstream itemInfile(directory + "/items.txt");
	// A temporary string variable for parsing purposes.
	string line;
	char delimiter = ',';

	// Initialize username list from file
	while (getline(userInfile, line)) {
		insert_user(line);
	}

	// Initialize items list from file.
	while (getline(itemInfile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);

		// [0] is the data type
		// [x-y] will be the following data, e.g. "name" "price" etc.

		if (parts[0] == "item" && parts.size() == 5)
			insert_item(generate_item(parts));
		else if (parts[0] == "household" && parts.size() == 8)
			insert_item(generate_household(parts));
		else if (parts[0] == "book" && parts.size() == 8)
			insert_item(generate_book(parts));
		else if (parts[0] == "toy" && parts.size() == 7)
			insert_item(generate_toy(parts));
		else if (parts[0] == "electronic" && parts.size() == 7)
			insert_item(generate_electronic(parts));
	}
}

void Database::set_directory(string directory){
	this->directory = directory;
	// Input file that stores usernames
	ifstream userInfile(directory + "/users.txt");
	// Input file that stores item data in comma separated format.
	ifstream itemInfile(directory + "/items.txt");
	// A temporary string variable for parsing purposes.
	string line;
	char delimiter = ',';

	// Initialize username list from file
	while (getline(userInfile, line)) {
		insert_user(line);
	}

	// Initialize items list from file.
	while (getline(itemInfile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);

		// [0] is the data type
		// [x-y] will be the following data, e.g. "name" "price" etc.

		if (parts[0] == "item" && parts.size() == 5)
			insert_item(generate_item(parts));
		else if (parts[0] == "household" && parts.size() == 8)
			insert_item(generate_household(parts));
		else if (parts[0] == "book" && parts.size() == 8)
			insert_item(generate_book(parts));
		else if (parts[0] == "toy" && parts.size() == 7)
			insert_item(generate_toy(parts));
		else if (parts[0] == "electronic" && parts.size() == 7)
			insert_item(generate_electronic(parts));
	}
}

vector<string> Database::tokenize(const string &line) {
	vector <string> parts;
	char delimiter = ',';

	stringstream ss;
	ss.str(line);
	string item;
	while (getline(ss, item, delimiter)) {
		parts.push_back(item);
	}
	return parts;
}

void Database::insert_user(string user) {
	user_table.push_back(user);
}

void Database::insert_item(Item item) {
	item_table.push_back(item);
}

string Database::generate_user(vector <string> values) {
	return string(values[1]);
}
Item Database::generate_item(vector <string> values) {
	return Item(values[1], stof(values[2]), stoi(values[3]), values[4]);
}
Household Database::generate_household(vector<string> values) {
	return Household(values[1], stof(values[2]), stoi(values[3]), values[4], values[5], values[6], values[7]);
}
Book Database::generate_book(vector<string> values) {
	return Book(values[1], stof(values[2]), stoi(values[3]), values[4], values[5], values[6], values[7]);
}
Toy Database::generate_toy(vector<string> values) {
	return Toy(values[1], stof(values[2]), stoi(values[3]), values[4], values[5], stoi(values[6]));
}
Electronic Database::generate_electronic(vector<string> values) {
	return Electronic(values[1], stof(values[2]), stoi(values[3]), values[4], values[5], values[6]);
}


bool Database::search_user(string value) {
	for (int i = 0; i != user_table.size(); i++) {
		if (user_table[i] == value) {
			return true; // User exists.
		}
	}
	return false; // User does not exist.
}

void Database::search_item(string value) {
	for (int i = 0; i != item_table.size(); i++) {
		if (item_table[i].name == value) {
			item_table[i].print_details();
		}
	}
}

void Database::print(string type) {
	for (int i = 0; i != item_table.size(); i++) {
		if (item_table[i].type == type) {
			item_table[i].print_details();
		}
	}
}

void Database::print_all() {
	for (int i = 0; i != item_table.size(); i++) {
		item_table[i].print_details();
	}
}

void Database::updateCartInDatabase(vector<Item> items,vector<int> quantity){
	
}

void Database::addOrderToDatabase(string user, vector<Item> items,vector<int> quantity,float total,string address,string payment){
	
}

void Database::getCartFromDatabase(vector<Item> &items,vector<int> &quantity){
	
}

//returns a vector of vectors containing info about the orders
vector<vector<string>> Database::get_order_history(string user){
	ifstream orderInfile(directory + "/" + user + ".txt");
	// A temporary string variable for parsing purposes.
	string line;
	char delimiter = ',';
	vector<vector<string>> orders;
	
	// Initialize items list from file.
	while (getline(orderInfile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);
		orders.push_back(parts);
	}
	return orders;
}

