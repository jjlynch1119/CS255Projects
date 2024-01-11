//Jeremy Lynch, CS255, P01255, ShoppingCart class for Interactive Shopping Cart

#include <iostream>
#include "ShoppingCart.h"
#include "DateUtility.h"

using namespace std;

ShoppingCart::ShoppingCart(string name) {
	customerName = name;
	currentDate = getDateString();
}

string ShoppingCart::getCustomerName() const {
	return customerName;
}

string ShoppingCart::getCurrentDate() const {
	return currentDate;
}

int ShoppingCart::getItemCount() const {
	int total = 0;

	for (int i = 0; i < cart.size(); i++) {
		total += cart.at(i).getItemQuantity();
	}

	return total;
}

int ShoppingCart::findItemInCart(string name) {
	int index;

	for (index = 0; index < cart.size(); ++index) {
		if (cart.at(index).getItemName() == name)
			break;
	}
	return index;
}

void ShoppingCart::addItemToCart(Item item) {
	if (findItemInCart(item.getItemName()) == cart.size()) { //find new way to find the item	
		cart.push_back(item);
		cout << "\n\n     >>> Item " << item.getItemName() << " added to cart <<<\n\n\n";
	} else if (findItemInCart(item.getItemName()) < cart.size()) {
		cout << "\n\n     >>> Item " << item.getItemName() << " already in cart <<<\n\n\n";
	}
}

void ShoppingCart::changeItemQuantity(string name, int quantity) {
	if (findItemInCart(name) == cart.size()) {
		cout << "\n\n     >>> Item " << name << " not in cart <<<\n\n\n";
	} else if (findItemInCart(name) < cart.size()) {
		cart.at(findItemInCart(name)).setItemQuantity(quantity);
		cout << "\n\n     >>> Item " << name << " quantity changed to " << quantity << " <<<\n\n\n";
	}
}

void ShoppingCart::changeItemPrice(string name, double price) {
	if (findItemInCart(name) == cart.size()) {
		cout << "\n\n     >>> Item " << name << " not in cart <<<\n\n\n";
	} else if (findItemInCart(name) < cart.size()) {
		cart.at(findItemInCart(name)).setItemPrice(price);
		cout << "\n\n     >>> Item " << name << " price changed to $" << price << " <<<\n\n\n";
	}
}

void ShoppingCart::removeItemFromCart(string name) {
	if (findItemInCart(name) == cart.size()) {
		cout << "\n\n     >>> Item " << name << " not in cart <<<\n\n\n";
	} else if (findItemInCart(name) < cart.size()) {
		cart.erase(cart.begin() + findItemInCart(name));
		cout << "\n\n     >>> Item " << name << " removed from cart <<<\n\n\n";
	}
}

void ShoppingCart::outputCartInfo() {
	double total = 0.0;

	for (int i = 0; i < cart.size(); i++) {
		cout << "     ";
		cart.at(i).outputItemInfo();
		cout << "\n";
		total += cart.at(i).getItemPrice() * cart.at(i).getItemQuantity();
	}

	if (total == 0.0)
		cout << "\n\n     >>> Shopping Cart is empty <<<\n\n\n";
	else
		cout << "\n\n     Total: $" << total << "\n\n\n";
}