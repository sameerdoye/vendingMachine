#pragma once
#include <vector>
#include <string>

enum class eProduct_Code : int
{
    min=0,
    chips_Lays,
    chips_haldiram,
    drink_pepsi,
    drink_coke,
    biscuit_monaco,
    biscuit_goodDay,
    max
};


struct Product
{
    std::string name;
    int quantity;
    float price;
    eProduct_Code Code;
};

typedef std::vector <Product> stock_t;

struct TransactionInfo
{
    eProduct_Code itemCode;
    int itemQuantity;
    float orderAmount;
    float moneyReceived;
};

