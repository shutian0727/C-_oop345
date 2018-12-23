//Project: ms3
//CustomerOrder.cpp
//Name: Shutian Xu
//ID: 109783175
//Date:11/30/2018

#ifndef LINEMANAGER_H
#define LINEMANAGER_H


#include <iostream>
#include <deque>
#include <fstream>
#include <vector>
#include "CustomerOrder.h"
#include "Task.h"
#include "Item.h"

class LineManager
{
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;		//Queue of Customer Orders to be filled
	std::deque<CustomerOrder> Completed;		//Queue of Customer Orders completed
	unsigned int CustomerOrder_Count;			//The number of customer orders the process started with
												//starting point
	size_t startindex;
	size_t endindex;//ending point
	//static std::string m;_stopPoint;
public:
	//Constructor sets the assembly line up by setting up the tasks pNextTask information
	//and moves all the CustomerOrder objects into the ToBeFilled queue
	LineManager(std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);

	//Processes each assembly line task and moves the CustomerOrders through the line
	//Returning true if all items have been completed
	bool Run(std::ostream&);
};
#endif // !LINEMANAGER_H
