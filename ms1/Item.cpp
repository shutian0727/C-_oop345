// homework: ms1
//file: Items.cpp
//Name: Shutian Xu
//Date: 11/9/2018
#include "Item.h"
#include "Utilities.h"

 unsigned int Item::field_width=0;
 //Extract a record from the items file and parses the data
Item::Item(std::string& record) {
	bool more = true;
	size_t pos = 0;
	size_t count = 0;
	Utilities util;
	util.setFieldWidth(field_width);
	while (more && count<4) {
		if (count == 0) name = util.extractToken(record, pos, more);
		else if (count == 1) serialNumber = (unsigned)std::stoi(util.extractToken(record, pos, more));
		else if (count == 2) Quantity = (unsigned int)std::stoi(util.extractToken(record, pos, more));
		else description = util.extractToken(record, pos, more);
		count++;
	}
	if (field_width < static_cast<int>(util.getFieldWidth())) {
		field_width = static_cast<int>(util.getFieldWidth());
	}
}

const std::string& Item::getName() const {
	return name;
}

const unsigned int Item::getSerialNumber() {
	return serialNumber++;

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
	os << std::setw(13) << std::left << std::fixed << name;
	os << "[" << serialNumber << "] Quantity " << std::left << std::setw(4) << Quantity;
	os << "Description: " << description << std::endl;
}