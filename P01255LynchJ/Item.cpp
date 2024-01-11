//Jeremy Lynch, CS255, P01255, Item class for Interactive Shopping Cart

#include <iostream>
#include <iomanip>
#include "Item.h"
using namespace std;

Item::Item(string name, double price, int quantity) {
	itemName = name;
	itemPrice = price;
	itemQuantity = quantity;
}

void Item::setItemName(string name) {
	itemName = name;
}

void Item::setItemPrice(double price) {
	itemPrice = price;
}

void Item::setItemQuantity(int quantity) {
	itemQuantity = quantity;
}

string Item::getItemName() const {
	return itemName;
}

double Item::getItemPrice() const {
	return itemPrice;
}

int Item::getItemQuantity() const {
	return itemQuantity;
}

void Item::outputItemInfo() {
	cout << itemName << " " << itemQuantity << fixed << setprecision(2) << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice;
}