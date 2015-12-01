#include "DB.h"
#include <fstream>


vector<Order*> DB::_orders;

void DB::addOrder(Order* order) {
	_orders.push_back(order);
}

void DB::removeOrder(int orderId) {
	for (int i = 0; i < _orders.size(); i++) {
		if (orderId == _orders[i]->orderId) {
			_orders[i]->isValid = false;
		}
	}
}

vector<Order*> DB::getOrders() {
	if (_orders.empty()) {
		loadFromFile();
	}
	vector<Order*> result;
	for (int i = 0; i < _orders.size(); i++) {
		if (_orders[i]->isValid) {
			result.push_back(_orders[i]);
		}
	}
	return result;
}

void DB::loadFromFile() {
	std::ifstream fs;
	fs.open("orderDB.txt");
	std::string line;
	getline(fs, line); // ignore first line
	for (std::string line; getline(fs, line);) {
		Order *order = Order::deserialize(line);
		if (order) {
			_orders.push_back(order);
		}
	}
	fs.close();
}

void DB::save() {
	std::ofstream fs;
	fs.open("orderDB.txt");
	fs << "OrderID" << '\t'
		<< "CustomerID" << '\t'
		<< "AccountRep" << '\t'
		<< "OrderDate" << '\t'
		<< "ShippedDate" << '\t'
		<< "ShippedBy" << '\t'
		<< "Freight" << '\t'
		<< "ShipName" << '\t'
		<< "ShipAddress" << '\t'
		<< "ShipCity" << '\t'
		<< "ShipRegion" << '\t'
		<< "ShipPostalCode" << '\t'
		<< "ShipCountry" << '\t'
		<< "IsValid"
		<< endl;

	for (int i = 0; i < _orders.size(); i++) {
		fs << _orders[i]->toString() << endl;
	}
	fs.close();
}