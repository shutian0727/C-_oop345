//CustomerOrder.cpp
//Name: Shutian Xu
//ID: 109783175
//Date:11/16/2018

#include "Item.h"
#include "Utilities.h"

using namespace std;

unsigned int Item::field_width = 1;

Item::Item(std::string& record) {
	bool more = true;
	size_t next_pos = 0; // changed

	Utilities u;
	
	
	name = u.extractToken(record, next_pos, more);
	if (more == true) {
		serialNumber = stoi(u.extractToken(record, next_pos, more));
		if (more == true) {
			Quantity = stoi(u.extractToken(record, next_pos, more));
			if (more == true) {
				description = u.extractToken(record, next_pos, more);
			}
		}
	}
	
	if (field_width < static_cast<int>(u.getFieldWidth())) {
		field_width = static_cast<int>(u.getFieldWidth());
	}
}

const std::string& Item::getName() const {
	return name;
}

const unsigned int Item::getSerialNumber() {
	int number = serialNumber;
	serialNumber += 1;
	return number;
}
const unsigned int Item::getQuantity() {
	return Quantity;
}
void Item::updateQuantity() {
	if (Quantity > 0) {
		Quantity -= 1;
	}
}
void Item::display(std::ostream& os, bool full) const {
	os << left << setw(13) << name;
	os << "[" << serialNumber << "] ";
	if (full = true) {
		os << "Quantity " << left << setw(4) << Quantity;
		os << "Description: " << description << "\n";
	}
	
}