#pragma once

class Item {
	// "name", price, quantity, "description"
public:
	string name;
	float price;
	int quantity;
	string description;

};

class Household : public Item {
	// "name", price, quantity, "description", "room", "size", "season"
public:
	string room;
	string size;
	string season;

};

class Book : public Item {
	// "name", price, quantity, "description", "author", "genre", "isbn"
public:
	string author;
	string genre;
	string isbn;

};

class Toy : public Item {
	// "name", price, quantity, "description", "brand", "age"
public:
	string brand;
	int age;


};

class Electronic : public Item {
	// "name", price, quantity, "description", "manufacturer", "category"
public:
	string manufacturer;
	string category;

};