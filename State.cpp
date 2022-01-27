#include "State.h"

#pragma once
#include <iostream>
#include <string>

#include "VMContext.h"
#include "Product.h"
#include "Stock_memory.h"
#include "IPayment.h"


using namespace std;

std::string State::isExit(std::string input)
{
	if (input == "-1")
		exit(0);
	return input;
}




Idle::Idle()
{
	VMC::getVMC().resetContext();
}

State* Idle::handleInput()
{
	VMC::getVMC().getStock().printStock();
	cout << "\n Type '-1' at any stage for Exit" ;
	cout << "\n Select product code for purchase : ";

	cin >> mUser_input;

	isExit(mUser_input);

	int pCode = std::atoi(mUser_input.c_str());

	if (VMC::getVMC().getStock().validateProductCode(pCode))
	{
		if (VMC::getVMC().getStock().canDispense(static_cast<eProduct_Code> (pCode), 1))
		{
			VMC::getVMC().startSell();

			VMC::getVMC().getSell().itemCode = static_cast<eProduct_Code> (pCode);

			return new Quantity();
		}
		else
		{
			cout << " Product not available :" 
				<< VMC::getVMC().getStock().getProductName(static_cast<eProduct_Code> (pCode)) << endl;
		}
	}
	else
	{
		cout << "Invalid Product Code. Please Re-try\n";
	}

	return new Idle();
}

State* Quantity::handleInput()
{
	cout << "\n Select product Quantity for purchase : ";

	cin >> mUser_input;

	isExit(mUser_input);

	int quantity = std::atoi(mUser_input.c_str());

	if (quantity < 1)
	{
		cout << " Invalid Quantity, Please Retry " << endl;
		return new Quantity();
	}

	bool quantityAvailable = VMC::getVMC().getStock().canDispense(VMC::getVMC().getSell().itemCode, quantity);
	if (quantityAvailable)
	{
		VMC::getVMC().getSell().itemQuantity = quantity;

		VMC::getVMC().getSell().orderAmount = VMC::getVMC().getStock().getOrderAmount(
			VMC::getVMC().getSell().itemCode, quantity);

		cout << " Total amount to Pay : " << VMC::getVMC().getSell().orderAmount << endl;

		return new ReceiveMoney();
	}
	else
	{
		cout << "\n Product Quantity not available. Please Select Another Product.\n";
		return new Idle();
	}
};

State* ReceiveMoney::handleInput()
{
	VMC::getVMC().startPayment();

	VMC::getVMC().getPayment().blockMoney(VMC::getVMC().getSell().orderAmount);

	cout << "\n Enter the amount you want to pay :";
	cin >> mUser_input;

	isExit(mUser_input);

	float amount = std::strtof(mUser_input.c_str(), NULL);

	if (amount == 0)
	{
		cout << "\n Invalid amount entered, please Retry ";
		return new ReceiveMoney();
	}
	VMC::getVMC().getSell().moneyReceived = amount;

	if (VMC::getVMC().getPayment().HasEnoughMoney(
		VMC::getVMC().getSell().moneyReceived,
		VMC::getVMC().getSell().orderAmount))
	{
		return new Dispense();
	}
	else
	{
		cout << " Insufficient Money, returning it." << endl;

		VMC::getVMC().getPayment().returnChange(VMC::getVMC().getSell().moneyReceived);

		return new Idle();
	}
};

State* Dispense::handleInput()
{
	if (VMC::getVMC().getStock().Dispense(
		VMC::getVMC().getSell().itemCode,
		VMC::getVMC().getSell().itemQuantity))
	{
		cout << "-------------------------------" << endl;
		cout << " Dispensing " << VMC::getVMC().getSell().itemQuantity
			<< " " << VMC::getVMC().getStock().getProductName(VMC::getVMC().getSell().itemCode)
			<< endl;
		cout << "-------------------------------" << endl;

		VMC::getVMC().getPayment().returnChange(
			VMC::getVMC().getSell().moneyReceived
			- VMC::getVMC().getSell().orderAmount);
	}
	else
	{
		cout << " Error in Dispensing product" << endl;

		VMC::getVMC().getPayment().returnChange(VMC::getVMC().getSell().moneyReceived);
	}
	return new Idle();
};



