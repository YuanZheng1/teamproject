#pragma once

#include <vector>
#include "Order.h"

using namespace std;

class DB {
public:
	static vector<Order*> getOrders();
	static void addOrder(Order* order);
	static void removeOrder(int orderId);
	static void save();
	static void close();
private:

	DB() {}
	DB(const DB&) {};

	static void loadFromFile();
	static vector<Order*> _orders;
};