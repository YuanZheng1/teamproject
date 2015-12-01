#include "Order.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

static void split(vector<string>& tokens, const string &input, char delim) {
	stringstream ss(input);
	string item;
	while (getline(ss, item, delim)) {
		if (item.empty()) {
			continue;
		}
		tokens.push_back(item);
	}
}

Order* Order::deserialize(const std::string& input) {
	if (input.empty()) {
		return NULL;
	}

	vector<string> fields;
	split(fields, input, '\t');

	if (fields.size() < 13) {
		return NULL;
	}

	Order* order = new Order();
	order->orderId = std::atoi(fields[0].c_str());
	order->customerID = fields[1];
	order->accountRep = fields[2];
	order->orderDate = fields[3];
	order->shippedDate = fields[4];
	order->shippedBy = fields[5];
	order->freight = fields[6];
	order->shipName = fields[7];
	order->shipAddress = fields[8];
	order->shipCity = fields[9];
	order->shipRegion = fields[10];
	order->shipPostalCode = fields[11];
	order->shipCountry = fields[12];
	order->isValid = (fields.size() == 14 && fields[13] == "false") ? false : true;

	return order;
}

string Order::toString() {
	stringstream ss;
	ss << orderId << '\t'
	   << customerID << '\t'
	   << accountRep << '\t'
	   << orderDate << '\t'
	   << shippedDate << '\t'
	   << shippedBy << '\t'
	   << freight << '\t'
	   << shipName << '\t'
	   << shipAddress << '\t'
	   << shipCity << '\t'
	   << shipRegion << '\t'
	   << shipPostalCode << '\t'
	   << shipCountry << '\t'
	   << isValid;
	return ss.str();
}