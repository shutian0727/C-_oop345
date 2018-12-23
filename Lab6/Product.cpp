// Workshop 6 - STL Containers
// w6.cpp
// Student Name: Shutian Xu
// Student ID:109783175
// Date: Oct 24th 2018
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "Product.h"
#include "TaxableProduct.h"
#include "iProduct.h"
using namespace std;

namespace w6 {

	Product::Product() {
		product_num_ = 0;
		cost_ = 0.0;
	}

	Product::Product(int product_number, double cost) {
			product_num_ = product_number;
			cost_ = cost;
		}

	double Product::getPrice() const {
		return cost_;
	}



	void Product::display(std::ostream& os) const{
		os << setw(10) << product_num_ << fixed << setprecision(2);
		os << setprecision(2) << setw(10) << cost_;
	}



	

}
