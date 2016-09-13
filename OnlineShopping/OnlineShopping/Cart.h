#pragma once


//the Cart class
class Cart {
public:
	//Database dbManager;
	vector <Item> items;
	vector <int> quantity;
	float total;
	
	Cart(void);
	void addToCart(Item item, int num);
	void removeFromCart(Item item, int num);
};

//Constructor
Cart::Cart(void){
	//dbManager.getCartFromDatabase(&items, &quantity);
	for(int i=0;i<items.size();i++){
		total+= items[i].price*quantity[i];
	}
}

//adds an item to the cart
void Cart::addToCart(Item item, int num){
	int inList=0;
	for(int i=0;i<items.size();i++){
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
	//dbManager.updateCartInDatabase(items, quantity);
	total+= item.price*num;
}

//removes the selected item from the cart
void Cart::removeFromCart(Item item, int num){
	for(auto i=0;i<items.size();i++){
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
	//dbManager.updateCartInDatabase(items, quantity);
}

//the Order class, it inharits from Cart
class Order : public Cart{
	public:
	string address;
	string payment;

	Order(void);
	void Cancel();
	void Confirm();
	void updateAddress(string newAddress);
	void updatePayment(string newPayment);
};

Order::Order(void){
	//dbManager.getCartFromDatabase(&items, &quantity);
	for(int i=0;i<items.size();i++){
		total += items[i].price*this->quantity[i];
	}
}

//sets the contents of the cart to be empty
void Order::Cancel(){
	items.clear();
	quantity.clear();
	//dbManager.updateCartInDatabase(items, quantity);
}

//stores the order in the database and empties the cart
void Order::Confirm(){
	//dbManager.addOrderToCart(items, quantity, total, address, payment);
	items.clear();
	quantity.clear();
	//dbManager.updateCartInDatabase(items, quantity);
}

//updates the shipping address
void Order::updateAddress(string newAddress){
	address = newAddress;
}

//updates the payment info
void Order::updatePayment(string newPayment){
	payment = newPayment;
}
