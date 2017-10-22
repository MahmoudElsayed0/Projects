#pragma once
#include <iostream>
#include <string>
#include <forward_list>

// States
enum vendingMachineState {
	SELECT, QUANTITY, CALCULATION, UPDATE
};/*End states enum*/


  // Item we colud sell it
enum Brand {
	COKE = 100, PEPSEI = 200, SEVENUP = 300, MERNDA = 400
};/*End List of Brand enum*/

  // Customer 
class student {
public:
	std::string name;
	int points;
};/*End student class*/

  // Data of the item already in the vending machine 
class Soda {
public:
	Brand brandName;
	int inventory;
	int price;
};/*End Soda class*/


class vendingMachine {
private:
	vendingMachineState currentState;
public:
	// Selected by user
	Soda selectedSoda;
	// Constructor to load default product
	vendingMachine();
	// Load the machine with the default product
	void loadThevendingMachine();
	// Add new item to the machine that exists in the list
	void addItemtotheVendingMachine(Brand, int, int);
	// Show all the product in the machine
	void showVendingMachineCont();
	// User selection
	vendingMachineState _selectedDrink(int selectedDrink);
	// checks the input from user
	vendingMachineState checkIfavailbale(int order);
	// Update the Inventory
	vendingMachineState updateInventory(int);
	// list of all od the products
	std::forward_list<Soda> vendingMachineList;
	std::forward_list<Soda>::iterator vendingMachineIt;
};/*End vending machine class*/

