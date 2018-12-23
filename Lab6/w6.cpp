// Workshop 6 - STL Containers
// w6.cpp
// Student Name: Shutian Xu
// Student ID:109783175
// Date: Oct 24th 2018
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"

int main(int argc, char** argv) {

	std::ofstream ofs("Lab6Output.txt");

	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}
	ofs << std::fixed << std::setprecision(2);

	//Add your code here
	std::vector<w6::iProduct*> products;
	double sumcost = 0.0;
	std::ifstream file;
	file.open(argv[1]);
	w6::iProduct* p_iprd = nullptr;
	int i = 1;
	do {
		p_iprd = w6::readProduct(file);
		if (p_iprd != nullptr) {
			products.push_back(p_iprd);
		}
	} while (p_iprd != nullptr || !file.eof());

file.close();

ofs << "Product No      Cost Taxable" << std::endl;

for (unsigned int i = 0; i < products.size(); i++) {

	ofs << *products[i] ;

	sumcost += products[i]->getPrice();

}

ofs << std::setw(10) << "Total" << std::fixed;

ofs << std::setw(10) << std::setprecision(2) << sumcost << std::endl;


std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
std::cin.get();

ofs.close();
}
