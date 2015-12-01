#pragma once

#include <string>

class Order {
public:

	Order() : isValid(true) { }

	int orderId;
	std::string customerID;
	std::string	accountRep;
	std::string orderDate;
	std::string	shippedDate;
	std::string shippedBy;
	std::string freight;
	std::string shipName;
	std::string	shipAddress;
	std::string	shipCity;
	std::string	shipRegion;
	std::string	shipPostalCode;
	std::string	shipCountry;
	bool isValid;

	std::string toString();

	static Order* deserialize(const std::string& input);
};