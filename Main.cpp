// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

#include "VMContext.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    VMC::getVMC().run();

}

