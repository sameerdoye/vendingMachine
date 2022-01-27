#pragma once
#include "IStock.h"
#include <iostream>

#include "Product.h"

class Stock_memory : public IStock
{
public :
    Stock_memory();
     
    //stock_t& getStock() override;
   
    void printStock() override;
    
    bool canDispense(eProduct_Code Code, int quantity) ;
    
    bool Dispense(eProduct_Code Code, int quantity) ;
    
    bool validateProductCode(int value) ;

    float getOrderAmount(eProduct_Code Code, int quantity) ;

    std::string getProductName(eProduct_Code code) ;

private:

    std::vector <Product> mData;
    bool CheckAndDispense(eProduct_Code Code, int quantity, bool dispense_flag);

};

