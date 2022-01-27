#pragma once
#include "Product.h"

//! Base class to provide interfaec for Stock in vending machine
//! Stock details can be stored in choice of data storage 
//! Like DataBase, File on disk, Program Memory (vetor, map)
//! In this example used Program Memory

class IStock
{
public:
    
    virtual void printStock() = 0; // as this is a console App
    virtual bool Dispense(eProduct_Code Code, int quantity) = 0;
    virtual bool canDispense(eProduct_Code Code, int quantity) = 0;
    virtual bool validateProductCode(int value) = 0;
    virtual float getOrderAmount(eProduct_Code Code, int quantity) = 0;
    virtual std::string getProductName(eProduct_Code Code) = 0;
   // virtual ~IStock() { };

    // Additional APIs
    // virtual stock_t& getStock();
    // virtual void AddToStock();  // required for maintenence
};

// Future extensions of Stock Interface

class Stock_DataBase : public IStock
{

};

class Stock_File : public IStock
{

};