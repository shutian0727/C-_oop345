/**********************************************************
// OOP345 Workshop 4: Contaienrs
// File Notification.h
// Date 10/02/2018
// Name: Shutian XU
// ID:109783175
***********************************************************/


#ifndef _NOTIFICATIONS_H
#define _NOTIFICATIONS_H
#include <iostream>
#include "Message.h"

//here should be namespace w4, but the main file and output shows w5
namespace w5 {

//class Notifications holds an array of Messages and a counter to record number of messages
	class Notifications {
		private:
		Message* messages_;
		int Number;
		int Count;//object array size

	public:
		Notifications();//Default constructor
		Notifications(const Notifications& src);//Copy constructor
		Notifications& operator=(const Notifications& src);//Copy assignment operator
		Notifications(Notifications&& src);//Move constructor
		Notifications& operator=(Notifications&& src);//Move assignment operator
		~Notifications();// Destrcutor
		void operator+=(const Message& msg);//Operator function that adds a Message object to the set
		void display(std::ostream& os) const;//query displays the Message objects in the ofs file output stream

	};

}


#endif