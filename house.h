#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <random>

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
		std::vector<const House*> available;
		for (const auto& house : houses)
		{
			if (house->available())
				available.push_back(house.get());
		}



		std::random_device rd;
		std::mt19937 g(rd());
		int n = available.size();

		for (int i = available.size() - 1; i > 0; --i) {
			std::uniform_int_distribution<int> dist(0, i);
			int j = dist(g);
			std::swap(available[i], available[j]);
		}

		int count = std::min(5, static_cast<int>(available.size()));
		std::cout << "\nAvailable houses for today: \n";
		for (int i = 0; i < count; ++i) {
			available[i]->display();
		}


	}
};
