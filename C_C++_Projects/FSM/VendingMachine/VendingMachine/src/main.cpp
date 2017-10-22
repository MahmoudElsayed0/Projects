#include "VendingMachine.h"

int main(void)
{
	// Create vending machine with default product
	vendingMachine machine;

	// Initial vending machine state
	vendingMachineState currentState = SELECT;
	
	// Add new product to the machine from the Brand list
	machine.addItemtotheVendingMachine(MERNDA, 10, 4000);

	// The student 
	student M;
	M.name = "Mahmoud";
	M.points = 100000;

	while (true)
	{

		switch (currentState)
		{
		case SELECT:
			// 1. Display the current states vending machine and student.
			std::cout << "<<<<<<------------ Current Status ------------>>>>>>" << std::endl;
			std::cout << "[[[ Vending Machine ]]]" << std::endl;
			machine.showVendingMachineCont();
			std::cout << "[[[ Student ]]]" << std::endl;
			std::cout << "Student name: " << M.name << "   Student points: " << M.points << std::endl;
			std::cout << "<<<<<<-------------- END States -------------->>>>>>" << std::endl;
			// 2. Ask the user what drink they want.
			std::cout << "\nPlease select a drink form the available options: " << std::endl;
			// 3. Display the Soda names and corresponding ID values.
			std::cout << "COKE    = 100\nPEPSEI  = 200\nSEVENUP = 300\nMERNDA  = 400" << std::endl;
			// 4. User inputs the drink.
			int selectedDrink;
			std::cin >> selectedDrink;
			std::cin.clear();
			// 5. If valid drink selected go to quantity state, else go back to select state.
			currentState = machine._selectedDrink(selectedDrink);
			break;
		case QUANTITY:
			// 1. Ask the user how many he wants.
			int numberOfDrinks;
			std::cout << "How many drinks you would like?" << std::endl;
			std::cin >> numberOfDrinks;
			std::cin.clear();
			std::cout << "Your order is " << numberOfDrinks << " Soda(s)" << std::endl;
			// 2. Make sure that the number is correct and available.
			currentState = machine.checkIfavailbale(numberOfDrinks);
			break;
		case CALCULATION:
			int total;
			total = numberOfDrinks * machine.selectedSoda.price;
			std::cout << "The total cost of your soda(s) is: " << total << std::endl;
			std::cout<<std::endl;
			int payment;
			std::cout << "Please enter your payment: ";
			std::cin >> payment;
			std::cin.clear();
			if (payment < total || payment <= 0 || payment > M.points)
			{
				std::cout << "Invalid payment." << std::endl;
				currentState = SELECT;
				std::cout << std::endl << std::endl;
			}
			else
			{
				M.points = M.points - payment;
				int change = payment - total;
				M.points = M.points + change;
				std::cout << "Thank you. Your change is: " << change << std::endl;
				currentState = UPDATE;
			}
			
			break;
		case UPDATE:
			machine.updateInventory(numberOfDrinks);
			std::cout << "Inventory Updated" << std::endl;
			currentState = SELECT;
			std::cout << std::endl << std::endl;
			break;
		default:
			std::cout << "Error! Invalid State detacted.\n";
			break;
		}/*End switch currentState*/
	}/*End of while*/
	return 0;
}/*End main*/
