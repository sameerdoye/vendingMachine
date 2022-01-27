#include "VMContext.h"
#include "State.h"


VMC::VMC(IStock* ptr)
    : mStock(ptr),
    mPay_ptr(nullptr),
    pSell(nullptr)
{ }


VMC& VMC::getVMC()
{
    static VMC Obj(new Stock_memory());
    return Obj;
}

void VMC::run()
{
    State* pState = new Idle();
    while (1)
    {
        pState = pState->handleInput();
    }
}





TransactionInfo& VMC::getSell()
{
    return (*pSell);
}

IStock& VMC::getStock()
{
    return (*mStock);
}

IPayment& VMC::getPayment()
{
    return (*mPay_ptr);
}

void VMC::startSell()
{
    if (pSell != nullptr) {
        delete pSell;
    }
    pSell = new TransactionInfo({});
}

void VMC::startPayment()
{
    if (mPay_ptr != nullptr)
    {
        delete mPay_ptr;
    }
    mPay_ptr = new IPayment();
}

void VMC::resetContext()
{
    if (pSell != nullptr) {
        delete pSell;
        pSell = nullptr;
    }

    if (mPay_ptr != nullptr)
    {
        delete mPay_ptr;
        mPay_ptr = nullptr;
    }
}




