#include <iostream>
#include "house.h"

int main()
{
    House::RentalSys system;
    system.addHouse(std::make_unique<House>("123 Main St", 300));
    system.addHouse(std::make_unique<House>("456 Oak Ave", 200));
    int choice;
    while (true) 
    {
        std::cout << "1. Show available\n2. Rent\n3. Exit\nChoice: ";
        std::cin >> choice;
    }
    
    if(choice == 1)
    {
       system.

    }









}