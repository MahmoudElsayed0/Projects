#include "VendingMachine.h"

vendingMachine::vendingMachine()
{
	//load the vending machine with products 
	loadThevendingMachine();
}/*End constructor of vending machine*/


void  vendingMachine::loadThevendingMachine() {
	// Item currently in the vending machine
	Soda vendingMachine;
	// First
	vendingMachine.brandName = COKE;
	vendingMachine.inventory = 10;
	vendingMachine.price = 1000;
	vendingMachineIt = vendingMachineList.insert_after(vendingMachineList.before_begin(), vendingMachine);
	// Second 
	vendingMachine.brandName = PEPSEI;
	vendingMachine.inventory = 10;
	vendingMachine.price = 2000;
	vendingMachineIt = vendingMachineList.insert_after(vendingMachineIt, vendingMachine);
	// Third
	vendingMachine.brandName = SEVENUP;
	vendingMachine.inventory = 10;
	vendingMachine.price = 3000;
	vendingMachineIt = vendingMachineList.insert_after(vendingMachineIt, 1, vendingMachine);
}/*End load vending Machine function*/

void vendingMachine::addItemtotheVendingMachine(Brand name, int inv, int pric)
{
	// Add new item
	Soda vendingMachine;
	vendingMachine.brandName = name;
	vendingMachine.inventory = inv;
	vendingMachine.price = pric;
	vendingMachineIt = vendingMachineList.insert_after(vendingMachineIt, 1, vendingMachine);
}/*End add item to vending machine function*/

void vendingMachine::showVendingMachineCont()
{
	// Move in the list to show all the products
	for (auto vendingMachineItr = vendingMachineList.cbegin(); vendingMachineItr != vendingMachineList.cend(); ++vendingMachineItr)
	{
		switch ((*vendingMachineItr).brandName)
		{
		case 100:
			std::cout << "COKE    has " << (*vendingMachineItr).inventory << " drinks, "
				"and each costs " << (*vendingMachineItr).price << std::endl;
			break;
		case 200:
			std::cout << "PEPSIE  has " << (*vendingMachineItr).inventory << " drinks, "
				"and each costs " << (*vendingMachineItr).price << std::endl;
			break;
		case 300:
			std::cout << "SEVENUP has " << (*vendingMachineItr).inventory << " drinks, "
				"and each costs " << (*vendingMachineItr).price << std::endl;
			break;
		case 400:
			std::cout << "MERNDA  has " << (*vendingMachineItr).inventory << " drinks, "
				"and each costs " << (*vendingMachineItr).price << std::endl;
			break;
		default:
			std::cout << "Invalid item." << std::endl;
			break;
		}/*End switch*/
	}/*End for*/
}/*End show vending machine content*/

 /*Error if some edits happend in the arrange of the list*/
vendingMachineState vendingMachine::_selectedDrink(int selectedDrink)
{

	auto vendingMachineItr = vendingMachineList.cbegin();
	switch (selectedDrink)
	{
	case COKE:
		std::cout << "You have selected COKE" << std::endl;
		selectedSoda.brandName = (*vendingMachineItr).brandName;
		selectedSoda.inventory = (*vendingMachineItr).inventory;
		selectedSoda.price = (*vendingMachineItr).price;
		currentState = QUANTITY;
		break;
	case PEPSEI:
		std::cout << "You have selected PEPSEI" << std::endl;
		++vendingMachineItr;
		selectedSoda.brandName = (*(vendingMachineItr)).brandName;
		selectedSoda.inventory = (*vendingMachineItr).inventory;
		selectedSoda.price = (*vendingMachineItr).price;
		currentState = QUANTITY;
		break;
	case SEVENUP:
		std::cout << "You have selected SEVENUP" << std::endl;
		++++vendingMachineItr;
		selectedSoda.brandName = (*vendingMachineItr).brandName;
		selectedSoda.inventory = (*vendingMachineItr).inventory;
		selectedSoda.price = (*vendingMachineItr).price;
		currentState = QUANTITY;
		break;
	case MERNDA:
		std::cout << "You have selected MERNDA" << std::endl;
		++++++vendingMachineItr;
		selectedSoda.brandName = (*vendingMachineItr).brandName;
		selectedSoda.inventory = (*vendingMachineItr).inventory;
		selectedSoda.price = (*vendingMachineItr).price;
		currentState = QUANTITY;
		break;
	default:
		std::cout << "Invalid Drink Selected!" << std::endl;
		currentState = SELECT;
		break;
	}/*End switch selectedDrink*/

	return currentState;
}
vendingMachineState vendingMachine::checkIfavailbale(int order)
{
	switch (selectedSoda.brandName)
	{
	case COKE:
		if (order < 0 || order > selectedSoda.inventory)
		{
			std::cout << "Not Enough In Stock" << std::endl;
			currentState = SELECT;
			std::cout << std::endl << std::endl;
		}/*End if*/
		else
			currentState = CALCULATION;
		break;
	case PEPSEI:
		if (order < 0 || order > selectedSoda.inventory)
		{
			std::cout << "Not Enough In Stock" << std::endl;
			currentState = SELECT;
			std::cout << std::endl << std::endl;
		}/*End if*/
		else
			currentState = CALCULATION;
		break;
	case SEVENUP:
		if (order < 0 || order > selectedSoda.inventory)
		{
			std::cout << "Not Enough In Stock" << std::endl;
			currentState = SELECT;
			std::cout << std::endl << std::endl;
		}/*End if*/
		else
			currentState = CALCULATION;
		break;
	case MERNDA:
		if (order < 0 || order > selectedSoda.inventory)
		{
			std::cout << "Not Enough In Stock" << std::endl;
			currentState = SELECT;
			std::cout << std::endl << std::endl;
		}/*End if*/
		else
			currentState = CALCULATION;
		break;
	default:
		std::cout << "Invalid Ammount Received." << std::endl;
		currentState = SELECT;
		break;
	}/*End of switch machine.selectedSoda.brandName*/
	return currentState;
}

vendingMachineState vendingMachine::updateInventory(int order)
{
	auto vendingMachineItr = vendingMachineList.begin();
	switch (selectedSoda.brandName)
	{
	case COKE:
		selectedSoda.inventory = (*vendingMachineItr).inventory - order;
		(*vendingMachineItr).inventory = selectedSoda.inventory;
		currentState = SELECT;
		std::cout << std::endl << std::endl;
		break;
	case PEPSEI:
		++vendingMachineItr;
		selectedSoda.inventory = (*vendingMachineItr).inventory - order;
		++(*vendingMachineItr).inventory = selectedSoda.inventory;
		currentState = SELECT;
		std::cout << std::endl << std::endl;
		break;
	case SEVENUP:
		++++vendingMachineItr;
		selectedSoda.inventory = (*vendingMachineItr).inventory - order;
		(*vendingMachineItr).inventory = selectedSoda.inventory;
		currentState = SELECT;
		std::cout << std::endl << std::endl;
		break;
	case MERNDA:
		++++++vendingMachineItr;
		selectedSoda.inventory = (*vendingMachineItr).inventory - order;
		(*vendingMachineItr).inventory = selectedSoda.inventory;
		currentState = SELECT;
		std::cout << std::endl << std::endl;
		break;
	default:
		std::cout << "Error." << std::endl;
		currentState = SELECT;
		std::cout << std::endl << std::endl;
		break;
	}
	return currentState;
}
