#pragma once

class Item {
	// "name", price, quantity, "description"
public:
	string name;
	float price;
	int quantity;
	string description;

	Item();
	Item(string name, float price, int quantity, string description);
};

Item::Item(void) {}

Item::Item(string name, float price, int quantity, string description) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
}


class Household : public Item {
	// "name", price, quantity, "description", "room", "size", "season"
public:
	string room;
	string size;
	string season;

	Household(string name, float price, int quantity, string description, string room, string size, string season);
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

class Book : public Item {
	// "name", price, quantity, "description", "author", "genre", "isbn"
public:
	string author;
	string genre;
	string isbn;

	Book(string name, float price, int quantity, string description, string author, string genre, string isbn);
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

class Toy : public Item {
	// "name", price, quantity, "description", "brand", "age"
public:
	string brand;
	int age;

	Toy(string name, float price, int quantity, string description, string brand, int age);
};

Toy::Toy(string name, float price, int quantity, string description, string brand, int age) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
	this->brand = brand;
	this->age = age;
}

class Electronic : public Item {
	// "name", price, quantity, "description", "manufacturer", "category"
public:
	string manufacturer;
	string category;

	Electronic(string name, float price, int quantity, string description, string manufacturer, string category);
};

Electronic::Electronic(string name, float price, int quantity, string description, string manufacturer, string category) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->description = description;
	this->manufacturer = manufacturer;
	this->category = category;
}