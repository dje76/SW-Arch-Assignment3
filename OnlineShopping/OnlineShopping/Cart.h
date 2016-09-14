#pragma once

//the Cart class
class Cart {
public:
	Database dbManager;
	vector <Item> items;
	vector <int> quantity;
	float total;
	
	Cart(void);
	void addToCart(Item item, int num, string user);
	void set_cart(string user);
	void removeFromCart(Item item, int num, string user);
	void clear(string user);
};

//Constructor
Cart::Cart(void){
	dbManager.set_directory("Files");
}

void Cart::set_cart(string user){
	std::pair <vector<Item>,vector<int>> product = dbManager.getCartFromDatabase(items, quantity, user);
	items = product.first;
	quantity = product.second;

	for(unsigned int i=0;i<items.size();i++){
		total+= items[i].price*quantity[i];
	}
}

//adds an item to the cart
void Cart::addToCart(Item item, int num, string user){
	int inList=0;
	for(unsigned int i=0;i<items.size();i++){
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
	dbManager.updateCartInDatabase(items, quantity, user);
	total+= item.price*num;
}

//removes the selected item from the cart
void Cart::removeFromCart(Item item, int num, string user){
	for(unsigned int i=0;i<items.size();i++){
		if(items[i].name==item.name){
			if(quantity[i]>num){
				quantity[i]-=num;
				total-= item.price*num;
			}
			else{
				items.erase(items.begin()+i);
				quantity.erase(quantity.begin()+i);
				total-= item.price*quantity[i];
			}
			break;
		}
	}
	dbManager.updateCartInDatabase(items, quantity, user);
}

void Cart::clear(string user){
	items.clear();
	quantity.clear();
	total=0.00;
	dbManager.updateCartInDatabase(items, quantity, user);
}

//the Order class, it inharits from Cart
class Order : public Cart{
	public:
	string address;
	string payment;

	Order(void);
};

Order::Order(void){
}