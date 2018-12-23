//Project: Ms2
//CustomerOrder.cpp
//Name: Shutian Xu
//ID: 109783175
//Date:11/16/2018
#include <vector>
#include "Utilities.h"
#include "CustomerOrder.h"
#include "Item.h"

//using namespace std;

unsigned int CustomerOrder::field_width = 0;
//default constructor
CustomerOrder::CustomerOrder() {
}
//Constructor
CustomerOrder::CustomerOrder(std::string& str) {
	Utilities u;
	std::vector<std::string> items;
	size_t next_pos = -1;
	ItemCount = 0;
	bool more = true;
	if (more == true)
		Name = u.extractToken(str, next_pos, more);
	if (more == true)
		Product = u.extractToken(str, next_pos, more);
	while (more == true) {
		items.push_back(u.extractToken(str, next_pos, more));
		ItemCount++;
	}

	if (field_width < static_cast<int>(u.getFieldWidth())) {
		field_width = static_cast<int>(u.getFieldWidth());
	}

	ItemList = new ItemInfo*[ItemCount];

	for (size_t i = 0; i < items.size(); i++) {
		ItemList[i] = new ItemInfo(items[i]);
	}
}
//Move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& order) {
	ItemList = nullptr;
	*this = std::move(order);
}
//Move assignment operator
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) {
	if (this != &order) {
		//clear memory
		delete[] ItemList;
		ItemList = nullptr;
		//assign the values
		Name = order.Name;
		Product = order.Product;
		ItemCount = order.ItemCount;
		ItemList = new ItemInfo*[order.ItemCount];
		for (size_t i = 0; i < ItemCount; i++) {
			ItemList[i] = new ItemInfo(order.ItemList[i]->ItemName);
		}
		order.Name = "";
		order.Product = "";
		delete[] order.ItemList;
		order.ItemList = nullptr;
		order.ItemCount = 0;
	}
	return *this;

}

//Destructor
CustomerOrder::~CustomerOrder() {
	delete[] ItemList;
	ItemList = nullptr;
}


bool CustomerOrder::getOrderFillState() {

	for (size_t i = 0; i < ItemCount; i++) {
		if (ItemList[i]->FillState == false) {
			return false;
		}
		else {

			return true;
		}
	}
}

bool CustomerOrder::getItemFillState(std::string str) {
	for (size_t i = 0; i < ItemCount; i++) {
		if (ItemList[i]->ItemName == str) {
			return ItemList[i]->FillState;
		}
	}
}

void CustomerOrder::fillItem(Item& item, std::ostream& os) {

	for (size_t i = 0; i < ItemCount; i++) {
		if (ItemList[i]->ItemName == item.getName()) {
			ItemList[i]->FillState = true;
			os << "Filled " << Name << ", " << Product << "[" << item.getName() << "]\n";
		}
	}


}

void CustomerOrder::Display(std::ostream& os) {
	os << Name << std::endl;
	os << Product << std::endl;
	for (size_t i = 0; i < ItemCount; i++) {
		os << "[" << ItemList[i]->SerialNumber << "] " << ItemList[i]->ItemName << " - MISSING\n";
	}
}