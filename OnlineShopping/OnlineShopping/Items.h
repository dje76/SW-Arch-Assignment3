#pragma once

class Item {
	// "name", price, quantity, "description"
public:
	string type = "item";
	string name;
	float price;
	int quantity;
	string description;

	Item();
	Item(string name, float price, int quantity, string description);
	virtual void print_details();
	vector<string> get_details();
};

Item::Item(void) {}

Item::Item(string name, float price, int quantity, string description) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
}

void Item::print_details() {
	cout << "       Name: " << this->name << endl;
	cout << "      Price: " << this->price << endl;
	cout << "   Quantity: " << this->quantity << endl;
	cout << "Description: " << this->description << endl;
	cout << endl;
}

vector<string> Item::get_details() {
	vector<string> tokens;
	tokens.push_back("item");
	tokens.push_back(this->name);
	tokens.push_back(to_string(this->price));
	tokens.push_back(to_string(this->quantity));
	tokens.push_back(this->description);
	return tokens;
}

class Household : public Item {
	// "name", price, quantity, "description", "room", "size", "season"
public:
	string type = "household";
	string room;
	string size;
	string season;

	Household(string name, float price, int quantity, string description, string room, string size, string season);
	void print_details();
	vector<string> get_details();
};

Household::Household(string name, float price, int quantity, string description, string room, string size, string season) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
	this->room = room;
	this->size = size;
	this->season = season;
}

void Household::print_details() {
	cout << "       Name: " << this->name << endl;
	cout << "      Price: " << this->price << endl;
	cout << "   Quantity: " << this->quantity << endl;
	cout << "Description: " << this->description << endl;
	cout << "       Room: " << this->room << endl;
	cout << "       Size: " << this->size << endl;
	cout << "     Season: " << this->season << endl;
	cout << endl;
}

vector<string> Household::get_details() {
	vector<string> tokens;
	tokens.push_back("household");
	tokens.push_back(this->name);
	tokens.push_back(to_string(this->price));
	tokens.push_back(to_string(this->quantity));
	tokens.push_back(this->description);
	tokens.push_back(this->room);
	tokens.push_back(this->size);
	tokens.push_back(this->season);
	return tokens;
}

class Book : public Item {
	// "name", price, quantity, "description", "author", "genre", "isbn"
public:
	string type = "book";
	string author;
	string genre;
	string isbn;

	Book(string name, float price, int quantity, string description, string author, string genre, string isbn);
	void print_details();
	vector<string> get_details();
};

Book::Book(string name, float price, int quantity, string description, string author, string genre, string isbn) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
	this->author = author;
	this->genre = genre;
	this->isbn = isbn;
}

void Book::print_details() {
	cout << "       Name: " << this->name << endl;
	cout << "      Price: " << this->price << endl;
	cout << "   Quantity: " << this->quantity << endl;
	cout << "Description: " << this->description << endl;
	cout << "     Author: " << this->author << endl;
	cout << "      Genre: " << this->genre << endl;
	cout << "       ISBN: " << this->isbn << endl;
	cout << endl;
}

vector<string> Book::get_details() {
	vector<string> tokens;
	tokens.push_back("book");
	tokens.push_back(this->name);
	tokens.push_back(to_string(this->price));
	tokens.push_back(to_string(this->quantity));
	tokens.push_back(this->description);
	tokens.push_back(this->author);
	tokens.push_back(this->genre);
	tokens.push_back(this->isbn);
	return tokens;
}

class Toy : public Item {
	// "name", price, quantity, "description", "brand", "age"
public:
	string type = "toy";
	string brand;
	int age;

	Toy(string name, float price, int quantity, string description, string brand, int age);
	void print_details();
	vector<string> get_details();
};

Toy::Toy(string name, float price, int quantity, string description, string brand, int age) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
	this->brand = brand;
	this->age = age;
}

void Toy::print_details() {
	cout << "       Name: " << this->name << endl;
	cout << "      Price: " << this->price << endl;
	cout << "   Quantity: " << this->quantity << endl;
	cout << "Description: " << this->description << endl;
	cout << "      Brand: " << this->brand << endl;
	cout << "        Age: " << this->age << "+" << endl;
	cout << endl;
}

vector<string> Toy::get_details() {
	vector<string> tokens;
	tokens.push_back("toy");
	tokens.push_back(this->name);
	tokens.push_back(to_string(this->price));
	tokens.push_back(to_string(this->quantity));
	tokens.push_back(this->description);
	tokens.push_back(this->brand);
	tokens.push_back(to_string(this->age));
	return tokens;
}

class Electronic : public Item {
	// "name", price, quantity, "description", "manufacturer", "category"
public:
	string type = "electronic";
	string manufacturer;
	string category;

	Electronic(string name, float price, int quantity, string description, string manufacturer, string category);
	void print_details();
	vector<string> get_details();
};

Electronic::Electronic(string name, float price, int quantity, string description, string manufacturer, string category) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
	this->manufacturer = manufacturer;
	this->category = category;
}

void Electronic::print_details() {
	cout << "        Name: " << this->name << endl;
	cout << "       Price: " << this->price << endl;
	cout << "    Quantity: " << this->quantity << endl;
	cout << " Description: " << this->description << endl;
	cout << "Manufacturer: " << this->manufacturer << endl;
	cout << "Category: " << this->category << endl;
	cout << endl;
}

vector<string> Electronic::get_details() {
	vector<string> tokens;
	tokens.push_back("electronic");
	tokens.push_back(this->name);
	tokens.push_back(to_string(this->price));
	tokens.push_back(to_string(this->quantity));
	tokens.push_back(this->description);
	tokens.push_back(this->manufacturer);
	tokens.push_back(this->category);
	return tokens;
}