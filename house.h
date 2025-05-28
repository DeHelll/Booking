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

	bool rent() 
	{
		if (isAvailable) {
			isAvailable = false;
			return true;
		}
		return false;
	}

	void release() { isAvailable = true; }
    const std::string& getAddress() const { return address;}
	bool available() const { return isAvailable; }



};

class RentalSys {
	std::vector < std::unique_ptr<House>> houses;

public:
	void addHouse(std::unique_ptr<House> house) { houses.push_back(std::move(house)); }

	bool rentHouse(const std::string& targetAddress)
	{
		for (auto& house : houses)
		{
			if (house->available() && house->getAddress() == targetAddress)
			{
				return house->rent();
			}
		}
		return false;

	}


	void displayAvailable() const 
	{
		for(const auto& house : houses)
		{
			if (house->available())
				house->display();
		}

	}





};
