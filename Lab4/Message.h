/**********************************************************
// OOP345 Workshop 4: Contaienrs
// File Message.h
// Date 10/02/2018
// Name: Shutian XU
// ID:109783175
***********************************************************/

#ifndef _MESSAGE_H
#define _MESSAGE_H
#include <iostream>
#include <fstream>
#include <string>
//here should be namespace w4, but the main file and output shows w5
namespace w5 {

//Class Message holds the objects of message
	class Message {
		std::string message, user, reply, tweet;
	public:
		Message();//Default constructor
		Message(std::ifstream& in, char c);//Copy constructor retrieves records from file object, parses and stores its components in Message object using c as the character to delimit each record
		bool empty() const;//Query returns true if Message object is in a safe empty state
		void display(std::ostream&) const;//Displays the Message objects within the container 
	};
}

#endif
