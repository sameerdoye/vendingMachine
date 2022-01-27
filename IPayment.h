#pragma once
using namespace std;

class IPayment
{
public:
    virtual bool  HasEnoughMoney(float received, float required) { return required <= received; }
    
    virtual float blockMoney(float amt) { return amt; }
    
    virtual float returnChange(float amt) { 
        if(amt>0)
            cout << "Returning change : " << amt << endl;
        return amt; 
    }
   
    virtual ~IPayment() { }
};


// Future extensions of Payment Interface
class Cash : public IPayment
{

};

class Card : public IPayment
{

};

class UPI_QR : public IPayment
{

};