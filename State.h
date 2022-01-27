#pragma once
#include <iostream>
#include <string>

#include "VMContext.h"
#include "Product.h"
#include "Stock_memory.h"
#include "IPayment.h"


using namespace std;

//! 
//! This is abstract Base class for all the states.
//! Vending machine context would be using base class State* to call
//! handleInput() function for processing operations during each state.
//! 
//! handleInput() in each derived class should take input from user, 
//! validate it and decide on the next state transition.
//! 

class State
{
public:
	virtual State* handleInput() = 0;
	std::string isExit(std::string input);

protected:
	std::string mUser_input;

};


class Idle : public State
{
public:
	Idle();
	State* handleInput();
};

class Quantity : public State
{
public:
	Quantity() = default;
	State* handleInput();
};


class ReceiveMoney : public State
{
public:
	ReceiveMoney() = default;
	State* handleInput();
};

class Dispense : public State
{
public:
	Dispense() = default;
	State* handleInput();
	
};


