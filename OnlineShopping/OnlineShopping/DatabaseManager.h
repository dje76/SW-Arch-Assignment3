#pragma once

/*
Database consisting of two tables: Users and Items.
Requires a database.txt file to pull data from.
Will overwrite the text file upon completion to update information.
*/

class Database {
public:
	vector <User> user_table;
	vector <Item> item_table;

	Database(string filename);
	vector<string> tokenize(const string &line);
	void insert_user(User user);
	void insert_item(Item item);

	User generate_user(vector <string> values);
	Admin generate_admin(vector <string> values);
	Item generate_item(vector <string> values);

	int search_user(string value);
};

Database::Database(string filename) {
	ifstream infile(filename);
	string line;
	char delimiter = ',';

	// Loops through the text file and tokenizes each line.
	while (getline(infile, line)) {
		vector <string> parts;
		split(line, delimiter, parts);

		// [0] is the data type
		// [x] will be the following data, e.g. "name" "price" etc.

		if (parts[0] == "user") {
			insert_user(generate_user(parts));
		}
		else if (parts[0] == "admin") {
			insert_user(generate_admin(parts));
		}

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

void Database::insert_user(User user) {
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
	return Item();
}

int Database::search_user(string value) {
	for (auto it = user_table.begin(); it != user_table.end(); it++) {
		if (it->name == value) {
			return 1; // User exists.
		}
	}
	return -1; // User does not exist.
}