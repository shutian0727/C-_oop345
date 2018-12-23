//Project: ms3
//Name: Shutian Xu
//ID: 109783175
//Date:11/30/2018
#include <string>
#include "Task.h"

//Constructor
Task::Task(std::string& file) : Item::Item(file) {
	pNextTask = nullptr;
}


//This function fills the last order in the queue
void Task::RunProcess(std::ostream& os) {

	//size_t max = Orders.size();
	//size_t count = 0;

	if (!Orders.empty()) {
		if (!(Orders.back().getItemFillState(this->getName()))) {
			Orders.back().fillItem(*this, os);
		}
		//count++;
	}
}

//This function moves the completed task to the next part of the assembly line
bool Task::MoveTask() {
	if (Orders.empty() == false) {
		if (Orders.back().getItemFillState(this->getName()) == true && pNextTask != nullptr) {
			*pNextTask+=(std::move(Orders.back()));
			Orders.pop_back();
		}
	}
	else {
		return false;
	}
	return true;
}

//Sets up the pointer to the next task if the tasks names line up
void Task::setNextTask(Task& task) {
	pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder &src) {
	if (Orders.empty())
		return false;
	//remove the last order from queue and place it in src
	src = std::move(Orders.back());
	Orders.pop_back();
	return true;
}

void Task::Validate(std::ostream& os) {
	os << getName() << " --> ";
	os << (pNextTask ? pNextTask->getName() : "END OF LINE");
	os << std::endl;
}

//Move a CustomerOrder into the orders queue
Task& Task::operator+=(CustomerOrder&& newOrder) {

	Orders.push_front(std::move(newOrder));
	return *this;
}