#pragma once

/*
Database consisting of two tables: Users and Items.
Requires a database.txt file to pull data from.
Will overwrite the text file upon completion to update information.
*/

class Database {
public:
	vector <string> user_table;
	vector <Item> item_table;

	Database(string filename);
	vector<string> tokenize(const string &line);
	void insert_user(string user);
	void insert_item(Item item);

	User generate_user(vector <string> values);
	Admin generate_admin(vector <string> values);
	Item generate_item(vector <string> values);
	Household generate_household(vector<string> values);
	Book generate_book(vector<string> values);
	Toy generate_toy(vector<string> values);
	Electronic generate_electronic(vector<string> values);

	bool search_user(string value);
};

Database::Database(string directory) {
	ifstream infile(directory + "/database.txt");
	string line;
	char delimiter = ',';

	// Loops through the text file, tokenize parts, generates database.
	while (getline(infile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);

		// [0] is the data type
		// [x-y] will be the following data, e.g. "name" "price" etc.

		if (parts[0] == "user" && parts.size() == 2)
			insert_user(parts[1]);
		//else if (parts[0] == "admin" && parts.size() == 3)
		//	insert_user(generate_admin(parts));
		else if (parts[0] == "item" && parts.size() == 5)
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

User Database::generate_user(vector <string> values) {
	return User(values[1]);
}
Admin Database::generate_admin(vector <string> values) {
	return Admin(values[1], values[2]);
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
	for (int i = 0; i != size(user_table); i++) {
		if (user_table[i] == value) {
			return true; // User exists.
		}
	}
	return false; // User does not exist.
}