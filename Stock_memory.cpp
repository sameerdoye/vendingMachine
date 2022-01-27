#include "Stock_memory.h"


Stock_memory::Stock_memory() :
    mData({ {"Lays    ",5, 20, eProduct_Code::chips_Lays },
            {"Bingo   ",5, 25, eProduct_Code::chips_haldiram},
            {"Pepsi   ",5, 30, eProduct_Code::drink_pepsi},
            {"Coke    ",5, 35, eProduct_Code::drink_coke},
            {"Monaco  ",5, 10, eProduct_Code::biscuit_monaco},
            {"GoodDay ",5, 20, eProduct_Code::biscuit_goodDay} 
        })

{ }

/*
stock_t& Stock_memory::getStock()
{
    return mData;
}
*/

void Stock_memory::printStock()
{
    std::cout << "\t_____________________________\n";
    for (int i = 0; i + 1 < mData.size(); i += 2)
    {
        std::cout << "\t|  " << mData[i].name << "   |  " 
            << mData[i + 1].name << "   |\n";

        std::cout << "\t|  Rs. " << mData[i].price 
            << "     |  Rs. " 
            << mData[i + 1].price 
            << "     |\n";

        std::cout << "\t|  Qt " << mData[i].quantity 
            << "       |  Qt " 
            << mData[i + 1].quantity 
            << "       |\n";

        std::cout << "\t|             |             |\n";

        std::cout << "\t|  Code: " << static_cast<int> (mData[i].Code)
            << "    |  Code: " << static_cast<int> (mData[i + 1].Code) << "    |\n";

        std::cout << "\t|_____________|_____________| \n";
       
    }
    std::cout << "\t| |-----------------------| |\n";
    std::cout << "\t|_|                       |_|\n";

}

bool Stock_memory::canDispense(eProduct_Code Code, int quantity)
{
    return CheckAndDispense(Code, quantity, false);
}

bool Stock_memory::Dispense(eProduct_Code Code, int quantity) 
{
    return CheckAndDispense(Code, quantity, true);
}

bool Stock_memory::CheckAndDispense(eProduct_Code Code, int quantity, bool dispense_flag)
{
    bool result = false;
    for (auto& item : mData)
    {
        if (Code == item.Code)
        {
            if (item.quantity >= quantity)
            {
                if (dispense_flag)
                    item.quantity = item.quantity - quantity;
                
                result = true;
                break;
            }
        }
    }

    return result;
}


bool Stock_memory::validateProductCode(int value)
{
    return (static_cast<int>(eProduct_Code::min) < value
        && value < static_cast<int>(eProduct_Code::max));
}

float Stock_memory::getOrderAmount(eProduct_Code Code, int quantity)
{
    float result = 0;
    for (auto& item : mData)
    {
        if (Code == item.Code)
        {
            if (item.quantity >= quantity)
            {
                result = item.price * quantity;
            }
        }
    }

    return result;
}

std::string Stock_memory::getProductName(eProduct_Code Code)
{
    for (auto& item : mData)
    {
        if (Code == item.Code)
        {
            return item.name;
        }
    }
    return "";
}
