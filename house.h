#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class House {
protected:
	std::string address;
	double pricePerNight;
	bool isAvailable;

public:
	House(const std::string& _address, double _pricePerNight)
		: address(_address), pricePerNight(_pricePerNight), isAvailable(true){}

	virtual ~House() = default;

	virtual void display() const {
		std::cout << "Address: " << address
			<< "\nPrice per night: $" << pricePerNight
			<< "\nStatus: " << (isAvailable ? "Available" : "Booked") << "\n\n";
	}





};
