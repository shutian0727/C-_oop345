//Project: Ms2
//CustomerOrder.cpp
//Name: Shutian Xu
//ID: 109783175
//Date:11/16/2018
#include <vector>

#include "Item.h"
#include "CustomerOrder.h"
#include "Utilities.h"


using namespace std;

unsigned int CustomerOrder::field_width = 0;

//default constructor
CustomerOrder::CustomerOrder() {
	field_width = 0;
}
//Constructor
CustomerOrder::CustomerOrder(std::string& str){
	Utilities u;
	std::vector<std::string> items;
	size_t next_pos = 0;
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
		Name = order.Name;
		Product = order.Product;
		for (size_t i = 0; i < ItemCount; ++i) {
			delete ItemList[i];
			ItemList[i] = nullptr;
		}
		delete[] ItemList;
		//assign the values
		ItemCount = order.ItemCount;
		//ItemList = order.ItemList;
		ItemList = new ItemInfo*[order.ItemCount];
		for (size_t i = 0; i < ItemCount; i++) {
			ItemList[i] = order.ItemList[i];
				// new ItemList(order.ItemList)
			order.ItemList[i]=nullptr;
		}
		order.Name = "";
		order.Product = "";
		delete[] order.ItemList;
		order.ItemList = nullptr;
		order.ItemCount = 0u;
	}
	return *this;

}

//Destructor
CustomerOrder::~CustomerOrder() {
	delete[] ItemList;
	ItemList = nullptr;
}


bool CustomerOrder::getOrderFillState() {

	bool filled = true;
	for (size_t i = 0; i < ItemCount && filled; ++i) {
		if (!ItemList[i]->FillState)
			filled = false;
	}
	return filled;
}

bool CustomerOrder::getItemFillState(std::string str) {
	bool filled = true;
	for (size_t i = 0; i < ItemCount; i++) {
		if (ItemList[i]->ItemName == str) {
			if (ItemList[i]->FillState == false) {
				filled = false;
				break;
			};
		}
	}
	return filled;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os) {

	for (size_t i = 0; i < ItemCount; ++i) {
		if (ItemList[i]->ItemName == item.getName() && item.getQuantity()>0) {
			item.updateQuantity();
			ItemList[i]->SerialNumber = item.getSerialNumber();
			ItemList[i]->FillState = true;
			os << "Filled " << Name << ", " << Product << "[" << ItemList[i]->ItemName << "]" << endl;
		}
		else if (ItemList[i]->ItemName == item.getName()&& item.getQuantity()==0) {
			os << "Unable to fill " << Name << ", " << Product << "[" << ItemList[i]->ItemName << "]" << endl;
		}
	}

}

void CustomerOrder::Display(std::ostream& os) {
	if (!Name.empty()) {
		os << Name << " - " << Product << endl;
		for (size_t i = 0; i < ItemCount; ++i) {
			os << "["<< ItemList[i]->SerialNumber << "]" << ' ' << setfill(' ');
			os << ItemList[i]->ItemName << " - ";
			os << (ItemList[i]->FillState ? "FILLED" : "MISSING") << endl;
		}
		os << right;
	}
}