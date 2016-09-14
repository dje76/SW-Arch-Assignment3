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
	vector <Household> household_table;
	vector <Book> book_table;
	vector <Toy> toy_table;
	vector <Electronic> electronic_table;

	vector <Item> items_in_cart;
	vector <int> quantity_in_cart;
	vector<vector<string>> history;

	Database(void);
	Database(string filename);
	void set_directory(string directory);
	vector<string> tokenize(const string &line);
	void insert_user(string user);
	void insert_household(Household item);
	void insert_book(Book item);
	void insert_toy(Toy item);
	void insert_electronic(Electronic item);

	string generate_user(vector <string> values);
	Household generate_household(vector<string> values);
	Book generate_book(vector<string> values);
	Toy generate_toy(vector<string> values);
	Electronic generate_electronic(vector<string> values);

	vector< vector<string> > get_order_history(string user);
	bool search_user(string value);
	void print_all();
	void updateCartInDatabase(vector<Item> items,vector<int> quantity, string user);
	void addOrderToDatabase(string user, vector<Item> items,vector<int> quantity,float total,string address,string payment);
	std::pair <vector<Item>,vector<int>> getCartFromDatabase(vector<Item> items,vector<int> quantity, string user);
	void writeDB(vector<string> tokens, ofstream &file);
	void dumpDB();
};

Database::Database(void){}

Database::Database(string directory) {
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

		if (parts[0] == "household" && parts.size() == 8)
			insert_household(generate_household(parts));
		else if (parts[0] == "book" && parts.size() == 8)
			insert_book(generate_book(parts));
		else if (parts[0] == "toy" && parts.size() == 7)
			insert_toy(generate_toy(parts));
		else if (parts[0] == "electronic" && parts.size() == 7)
			insert_electronic(generate_electronic(parts));
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

		if (parts[0] == "household" && parts.size() == 8)
			insert_household(generate_household(parts));
		else if (parts[0] == "book" && parts.size() == 8)
			insert_book(generate_book(parts));
		else if (parts[0] == "toy" && parts.size() == 7)
			insert_toy(generate_toy(parts));
		else if (parts[0] == "electronic" && parts.size() == 7)
			insert_electronic(generate_electronic(parts));
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

void Database::insert_household(Household item) {
	household_table.push_back(item);
}

void Database::insert_book(Book item) {
	book_table.push_back(item);
}

void Database::insert_toy(Toy item) {
	toy_table.push_back(item);
}

void Database::insert_electronic(Electronic item) {
	electronic_table.push_back(item);
}

string Database::generate_user(vector <string> values) {
	return string(values[1]);
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

void Database::print_all() {
	for (int i = 0; i != household_table.size(); i++) {
		household_table[i].print_details();
	}
	for (int i = 0; i != book_table.size(); i++) {
		book_table[i].print_details();
	}
	for (int i = 0; i != toy_table.size(); i++) {
		toy_table[i].print_details();
	}
	for (int i = 0; i != electronic_table.size(); i++) {
		electronic_table[i].print_details();
	}
}

void Database::updateCartInDatabase(vector<Item> items,vector<int> quantity, string user){
	ifstream cartInfile(directory + "/cart.txt");
	// A temporary string variable for parsing purposes.
	string line;
	char delimiter = ',';
	vector<string> lines;
	string cart_line;
	string new_cart;
	int index=0;
	int size=0;

	// Initialize items list from file.
	while (getline(cartInfile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);
		if(parts[0] == user){
			cart_line = line;
			index = size;
		}
		lines.push_back(line);
		size++;
	}
	cartInfile.close();

	new_cart = user;
	for(int i=0;i<items.size();i++){
		new_cart = new_cart + "," + items[i].name + "," + std::to_string(quantity[i]);
	}
	lines[index] = new_cart;

	remove("Files/cart.txt");
	ofstream cartOutfile(directory + "/cart.txt");
	for(int i=0;i<lines.size();i++){
		cartOutfile << lines[i] << endl;
	}
	cartOutfile.close();
}

void Database::addOrderToDatabase(string user, vector<Item> items,vector<int> quantity,float total,string address,string payment){
	ifstream orderInfile(directory + "/" + user + ".txt");
	// A temporary string variable for parsing purposes.
	string line;
	char delimiter = ',';
	vector<string> lines;

	// Initialize items list from file.
	while (getline(orderInfile, line)) {
		lines.push_back(line);
	}
	orderInfile.close();

	string new_order = payment + "," + address + "," + to_string(total);
	for(int i=0;i<items.size();i++){
		new_order = new_order + "," + items[i].name + "," + to_string(quantity[i]) + "," + to_string(items[i].price);
	}
	lines.push_back(new_order);
	cout << new_order << std::endl;
	string filename = directory + "/" + user + ".txt";
	ofstream orderOutfile(filename);
	for(int i=0;i<lines.size();i++){
		orderOutfile << lines[i] << endl;
	}
	orderOutfile.close();
}

std::pair <vector<Item>,vector<int>> Database::getCartFromDatabase(vector<Item> items,vector<int> quantity, string user){
	ifstream cartInfile(directory + "/cart.txt");
	// A temporary string variable for parsing purposes.
	string line;
	char delimiter = ',';
	vector<string> cart;

	// Initialize items list from file.
	while (getline(cartInfile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);
		if(parts[0] == user){
			cart = parts;
			break;
		}
	}
	int cont = 0;
	for(int i=1;i<cart.size();i+=2){
		cont = 0;
		for(int j=0;j<household_table.size();j++){
			if(cart[i] == household_table[j].name){
				items_in_cart.push_back(household_table[j]);
				cont++;
				quantity_in_cart.push_back(std::stoi(cart[i+1]));
				break;
			}
			cont = 0;
		}
		if(cont){
			continue;
		}
		for(int j=0;j<book_table.size();j++){
			if(cart[i] == book_table[j].name){
				items_in_cart.push_back(book_table[j]);
				cont++;
				quantity_in_cart.push_back(std::stoi(cart[i+1]));
				break;
			}
			cont = 0;
		}
		if(cont){
			continue;
		}
		for(int j=0;j<toy_table.size();j++){
			if(cart[i] == toy_table[j].name){
				items_in_cart.push_back(toy_table[j]);
				quantity_in_cart.push_back(std::stoi(cart[i+1]));
				cont++;
				break;
			}
			cont = 0;
		}
		if(cont){
			continue;
		}
		for(int j=0;j<electronic_table.size();j++){
			if(cart[i] == electronic_table[j].name){
				items_in_cart.push_back(electronic_table[j]);
				quantity_in_cart.push_back(std::stoi(cart[i+1]));
				break;
			}
			cont = 0;
		}
	}

	items = items_in_cart;
	quantity = quantity_in_cart;
	std::pair <vector<Item>,vector<int>> product(items,quantity);
	cartInfile.close();
	return product;
}

//returns a vector of vectors containing info about the orders
vector<vector<string>> Database::get_order_history(string user){
	history.clear();
	ifstream orderInfile(directory + "/" + user + ".txt");
	// A temporary string variable for parsing purposes.
	string line;
	char delimiter = ',';

	// Initialize items list from file.
	while (getline(orderInfile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);
		history.push_back(parts);
	}
	orderInfile.close();
	return history;
}

// Add this at the very end. Outside main.
void Database::writeDB(vector<string> tokens, ofstream &file) {
	for (int i = 0; i < tokens.size(); i++) {
		if (i != tokens.size() - 1)
		file << tokens[i] << ',';
	else
		file << tokens[i] << endl;
	}//end for loop
}//end write function

void Database::dumpDB() {
	remove("Files/items.txt");
	ofstream outfile("Files/items.txt");

	for (auto it : household_table) {
		vector<string> tokens = it.get_details();
		writeDB(tokens, outfile);
	}
	for (auto it : book_table) {
		vector<string> tokens = it.get_details();
		writeDB(tokens, outfile);
	}
	for (auto it : toy_table) {
		vector<string> tokens = it.get_details();
		writeDB(tokens, outfile);
	}
	for (auto it : electronic_table) {
		vector<string> tokens = it.get_details();
		writeDB(tokens, outfile);
	}
}//end dump
