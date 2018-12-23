/**********************************************************
// OOP345 Workshop 4: Contaienrs
// File Notification.cpp
// Date 10/02/2018
// Name: Shutian XU
// ID:109783175
***********************************************************/
#include "Message.h"
#include <iostream>
#include "Notifications.h"
using namespace std;
//here should be namespace w4, but the main file and output shows w5
namespace w5 {
	Notifications::Notifications() {
		Count = 0;
		Number = 10;
		messages_ = nullptr;
	}


	Notifications::Notifications(const Notifications& src) {
		Count = 0;
		Number = 10;
		messages_ = new Message[Number];
		Count = src.Count;
		for (int i = 0; i < src.Count; i++) {
			messages_[i] = src.messages_[i];
		}
	}


	Notifications& Notifications::operator=(const Notifications& src) {
		Number = 10;
		if (this != &src) {
			if (Count == 0 && src.Count == 0) {

			}
			else if (Count != 0 && src.Count == 0) {
				delete[] messages_;
				messages_ = nullptr;
				Count = 0;
			}
			else if (Count == 0 && src.Count != 0) {
				messages_ = new Message[Number];
				Count = src.Count;

				for (size_t i = 0; i < Count; i++) {
					messages_[i] = src.messages_[i];
				}
			}
			else if (Count != 0 && src.Count != 0) {
				Count = src.Count;

				for (size_t i = 0; i < Count; i++) {
					messages_[i] = src.messages_[i];
				}
			}
		}
		return *this;
	}


	Notifications::Notifications(Notifications&& src) {
		Number = 10;
		Count = 0;
		messages_ = new Message[Number];
		delete[] messages_;
		messages_ = src.messages_;
		Count = src.Count;
		src.Count = 0;
		src.messages_ = nullptr;
	}


	Notifications& Notifications::operator=(Notifications&& src) {
		if (this != &src) {
			if (this->messages_ != nullptr) {
				delete[] this->messages_;
				this->Count = 0;
				this->messages_ = nullptr;
			}

			this->messages_ = src.messages_;
			this->Count = src.Count;

			src.messages_ = nullptr;
			src.Count = 0;
		}
		return *this;

	}


	Notifications::~Notifications() {
		delete[] this->messages_;
		this->Count = 0;
	}


	void Notifications::operator+=(const Message& msg) {
		Number = 10;
		if (Count == 0) {
			messages_ = new Message[Number];
		}
		if (Count < Number) {
			messages_[Count] = msg;
			Count++;
		}
	}


	void Notifications::display(std::ostream& os) const {

		for (int i = 0; i < Count; i++) {
			messages_[i].display(os);
			//os << "\n";
		}
	}

}



