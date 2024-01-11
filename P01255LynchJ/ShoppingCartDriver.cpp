//Jeremy Lynch, CS255, P01255, ShoppingCartDriver for Interactive Shopping Cart

// TO BE COMPLETED: ShoppingCartDriver.cpp
#include <iostream>
#include "ShoppingCart.h"
#include "DateUtility.h"
using namespace std;

char getMenuChoice();
void processMenuChoice(char, ShoppingCart&);

int main() {
	string custName;
	char choice;

	// COMPLETE THIS FUNCTION

	// Asks user to enter customer name
	// Displays title, customer name, and date
	// choice = getMenuChoice();
	//
	// set up while loop to check for choice of 'q'
	//		if not 'q', processMenuChoice
	//		call getMenuChoice() again
	cout << "**** Shopping Cart ****";
	cout << "\n\nEnter customer's name: ";
	getline(cin, custName);
	cout << "\nCustomer Name: " << custName << "  Today's Date: " << getDateString() << "\n\n";

	ShoppingCart theCart(custName);

	choice = getMenuChoice();

	do {
		processMenuChoice(choice, theCart);
		choice = getMenuChoice();
	} while (choice != 'q');

	cout << endl;

	return 0;
}

char getMenuChoice() {
	string menuOptions = "adcpstoq";
	char choice = ' ';

	// COMPLETE THIS FUNCTION
	//	Display the menu
	//	Consider using string function "find" to determine
	//		if the choice is one of the letters in menuOptions string above

	//  Once a "valid" choice is made, return the choice to "main()"

	 do {
		cout << "-- Online Shopping Menu --\n";
		cout << "     a - Add item to cart\n";
		cout << "     d - Remove item from cart\n";
		cout << "     c - Change item quantity\n";
		cout << "     p - Change item price\n";
		cout << "     o - Output shopping cart\n";
		cout << "     q - Quit\n\n\n";
		cout << "     Choose option: ";
		cin >> choice;

		if (menuOptions.find(choice) != string::npos)
			break;
	 } while (true);

	return choice;
}

void processMenuChoice(char choice, ShoppingCart& theCart) {
	string name = "";
	double price = 0.0;
	int quantity = 0;

	Item userItem(name, price, quantity);

	// COMPLETE THE "switch" below
	//	refer to sample runs for I/O formatting

	switch (choice) {
	case 'a':
		cin.ignore();
		// get the item name, price, quantity from user
		// call addItemToCart with an Item object as an argument
		cout << "\n\n-- Add Item to Cart --";
		cout << "\n     Enter the item name: ";
		getline(cin, name);
		userItem.setItemName(name);
		cout << "     Enter the item price: ";
		cin >> price;
		userItem.setItemPrice(price);
		cout << "     Enter the item quantity: ";
		cin >> quantity; 
		userItem.setItemQuantity(quantity);

		theCart.addItemToCart(userItem);
		break;

	case 'd':
		cin.ignore();
		// get the item name from user
		// call removeItemFromCart with name as the argument
		cout << "\n\n-- Remove Item from Cart --";
		cout << "\n     Enter name of item to remove: ";
		getline(cin, name);

		theCart.removeItemFromCart(name);

		break;

	case 'c':
		cin.ignore();
		// get the item name and new quantity from user
		// call changeItemQuantity with name and new quantity as arguments
		cout << "\n\n-- Change Item Quantity --";
		cout << "\n     Enter the item name: ";
		getline(cin, name);
		cout << "     Enter the item quantity: ";
		cin >> quantity;

		theCart.changeItemQuantity(name, quantity);

		break;

	case 'p':
		cin.ignore();
		// get the item name and new price from user
		// call changeItemPrice with name and new price as arguments
		cout << "\n\n-- Change Item Price --";
		cout << "\n     Enter the item name: ";
		getline(cin, name);
		cout << "     Enter the new price: ";
		cin >> price;

		theCart.changeItemPrice(name, price);

		break;

	case 'o':
		cin.ignore();
		// display cart info -- see sample runs
		cout << "\n\n-- Output Shopping Cart --";
		cout << "\n     " << theCart.getCustomerName() << "'s Shopping Cart - " << theCart.getCurrentDate();
		cout << "\n\n\n     Number of Items: " << theCart.getItemCount();
		cout << "\n     ---------------------\n";
		theCart.outputCartInfo();

		break;
	}
}
