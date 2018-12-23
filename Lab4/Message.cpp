/**********************************************************
// OOP345 Workshop 4: Contaienrs
// File Message.cpp
// Date 10/02/2018
// Name: Shutian XU
// ID:109783175
***********************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "Message.h"
#include "Notifications.h"
using namespace std;

//here should be namespace w4, but the main file and output shows w5
namespace w5 {
	Message::Message() {
		message = "";
		user = "";
		reply = "";
		tweet = "";
	}


	Message::Message(std::ifstream& in, char c) {
		string temp;
		int index;

		getline(in, temp);
		index = temp.find(c);// postion of char for the 1st time

		if (index != -1) {
			user = temp.substr(0, index);
			temp = temp.substr(index + 1, temp.length() - index);
		}

		if (temp[0] == '@') {
			index = temp.find(c);
			reply = temp.substr(1, index - 1);
			tweet = temp.substr(index + 1, temp.length() - index);
		}
		else {
			tweet = temp;
		}
	}


	bool Message::empty() const {
		if (tweet == "") {
			return true;
		}
		else {
			return false;
		}
	}

	void Message::display(std::ostream& os) const {
		os << "Message" << endl;
		os << " User  : " << user << endl;
		if (!reply.empty())
		{
			os << " Reply : " << reply << endl;
		}
		os << " Tweet : " << tweet << endl << endl;

		if (!reply.empty()) {
			os << endl;
		}
	}
}



