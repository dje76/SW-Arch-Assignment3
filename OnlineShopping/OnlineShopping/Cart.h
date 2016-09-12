#pragma once

#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "Items.h"
#include "DatabaseManager.h"

//the Cart class
class Cart {
public:
	DatabaseManager dbManager = new DatabaseManager();
	vector <Item> items = new vector<Items>();
	vector <int> quantity = new vector<int>();
	float total;

	addToCart(Item item, int num);
	removeFromCart(Item item, int num);
};

//Constructor
Cart::Cart(){
	dbManager.getCartFromDatabase(&items, &quantity);
	for(int i=0;i<items.size;i++){
		total+= items[i].price*quantity[i];
	}
}

//adds an item to the cart
void Cart::addToCart(Item item, int num){
	int inList=0;
	for(int i=0;i<items.size;i++){
		if(items[i].name==item.name){
			quantity[i]+=num;
			inList=1;
			break;
		}
	}
	if(inList==0){
		items.push_back(item);
		quantity.push_back(num);
	}
	dbManager.updateCartInDatabase(items, quantity);
	total+= item.price*num;
}

//removes the selected item from the cart
void removeFromCart(Item item, int num{
	for(int i=0;i<items.size;i++){
		if(items[i] == null){
			continue;
		}
		if(items[i]name==item.name){
			if(quantity[i]>num){
				quantity[i]-=num;
				total-= item.price*num;
			}
			else(quantity[i]<num){
				items.erase(i);
				quantity.erase(i);
				total-= item.price*quantity[i];
			}
			break;
		}
	}
	dbManager.updateCartInDatabase(items, quantity);
}

//the Order class, it inharits from Cart
class Order : public Cart{
	public:
	address string;
	payment string;

	Cancel();
	Confirm();
	updateAddress(string newAddress);
	updatePayment(string newPayment);
}

Order::Order(){
	dbManager.getCartFromDatabase(&items, &quantity);
	for(int i=0;i<items.size;i++){
		total += items[i].price*quantity[i];
	}
}

//sets the contents of the cart to be empty
void Order:Cancel(){
	items.clear();
	quantity.clear();
	dbManager.updateCartInDatabase(items, quantity);
}

//stores the order in the database and empties the cart
void Confirm(){
	dbManager.addOrderToCart(items, quantity, total, address, payment);
	items.clear();
	quantity.clear();
	dbManager.updateCartInDatabase(items, quantity);
}

//updates the shipping address
void Order::updateAddress(string newAddress){
	address = newAddress;
}

//updates the payment info
void Order::updatePayment(string newPayment){
	payment = newPayment;
}
