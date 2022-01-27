#pragma once


#include "Stock_memory.h"
#include "Product.h"
#include "IPayment.h"

class VMC
{
public:
    static VMC& getVMC();

    TransactionInfo& getSell();

    IStock& getStock();

    IPayment& getPayment();

    void startSell();

    void startPayment();

    void resetContext();

    void run();

private:

    VMC(IStock* ptr);
    IStock* mStock;
    TransactionInfo* pSell;
    IPayment* mPay_ptr;
};




