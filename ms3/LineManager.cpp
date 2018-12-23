//Project: ms3
//CustomerOrder.cpp
//Name: Shutian Xu
//ID: 109783175
//Date:11/30/2018

#include "LineManager.h"
#include "Utilities.h"


//Constructor sets the assembly line up by setting up the tasks pNextTask information
//and moves all the CustomerOrder objects into the ToBeFilled queue
LineManager::LineManager(std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customerorders) {
	Utilities util;
	std::ifstream file(fileName);
	std::string record;
	size_t time = 0;
	CustomerOrder_Count = customerorders.size();
	if (file)                               // changed
	{
		while (!file.eof())
		{
			bool more = true;
			size_t index = 0u, formerTaskIndex = 0u;
			std::getline(file, record);
			std::string formerTask = util.extractToken(record, index, more);
			std::string nextTask = "";

			if (more)
				nextTask = util.extractToken(record, index, more);

			for (size_t i = 0; i < tasks.size(); ++i) {
				if (tasks[i]->getName() == formerTask) {
					if (time == 0) startindex = i;
					formerTaskIndex = i;
					time++;
					break;
				}
			}
			if (!nextTask.empty()) {
				for (size_t i = 0; i < tasks.size(); ++i) {
					if (tasks[i]->getName() == nextTask) {
						tasks[formerTaskIndex]->setNextTask(*tasks[i]);
						break;
					}
				}
			}
			else {
				endindex = formerTaskIndex;
			}
			/*for (auto task : AssemblyLine)
				task->Validate(std::cout);
*/


//stores the starting point
//m_startPoint = tasks.back()->getName();
//stores the ending point
//m_stopPoint = tasks[tasks.size() - 2]->getName();
//CustomerOrder_Count = ToBeFilled.size();
		}
	}
	for (size_t i = 0; i < customerorders.size(); i++) {
		ToBeFilled.push_front(std::move(customerorders[i]));
	}
	AssemblyLine = tasks;
}

//Processes each assembly line task and moves the CustomerOrders through the line
//Returning true if all items have been completed

bool LineManager::Run(std::ostream& os) {
	//size_t startIndex = 0u, stopIndex = 0u;
	//bool startSetUp = false, stopSetUp = false;

	size_t position = 0u;
	//size_t orderNum = ToBeFilled.size();
	for (size_t i = 0; i < AssemblyLine.size(); ++i)
		if (AssemblyLine[i]->getName() == "Power Supply")
		{
			position = i;
			break;
		}

	if (!ToBeFilled.empty()) {
		*AssemblyLine[position] += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}
	for (auto task : AssemblyLine)
		task->RunProcess(os);

	for (size_t i = 0; i < AssemblyLine.size(); ++i)
		if (AssemblyLine[i]->getName() == "SSD")
		{
			position = i;
			break;
		}

	CustomerOrder COcompleted;
	if (AssemblyLine[position]->getCompleted(COcompleted))
		Completed.push_back(std::move(COcompleted));

	for (auto task : AssemblyLine)
		task->MoveTask();

	//if (i == AssemblyLine.size() - 1) {
			//for (size_t j = 0; j < CustomerOrder_Count; j++)
	//}


	if (Completed.size() == CustomerOrder_Count) {
		os << std::endl << "COMPLETED" << std::endl;
		for (size_t i = 0; i < Completed.size(); i++)
			Completed[i].Display(os);
		return true;
	}

	return false;
}
