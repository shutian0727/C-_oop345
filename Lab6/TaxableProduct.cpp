#include <iomanip>
#include "TaxableProduct.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Product.h"
using namespace std;

namespace w6 {

	TaxableProduct::TaxableProduct(int product_number, double cost, char taxcode) :Product(product_number, cost)
	{
		switch (taxcode) {
		case 'H':
			taxable_status_ = tax::HST;
			break;
		case 'P':
			taxable_status_ = tax::PST;
			break;
		default:
			taxable_status_ = tax::NONE;

		}
		 
	}


	double TaxableProduct::getPrice() const {

		double charge = Product::getPrice();
		if (taxable_status_ == tax::NONE) {
			return charge;
		}
		(taxable_status_ == tax::HST) ? charge *= 1.13 : charge *= 1.08;
		return charge;
	}


	void TaxableProduct::display(std::ostream& out) const {
		Product::display(out);
		out << " ";
		if (taxable_status_ == tax::HST) {
			out << "HST";
		}
		else if (taxable_status_ == tax::PST) {
			out << "PST";
		}
	}

	std::ostream& operator<<(std::ostream& out, const iProduct& iproduct) {
		iproduct.display(out);
		out << std::endl;
		return out;
	}

	iProduct* readProduct(std::ifstream& file) {
		int no;
		double price;
		char taxCode;
		iProduct* p_ipro = nullptr;
		file >> no;
		file >> price;
		file.get(taxCode);

		if (taxCode == '\n') {
			p_ipro = new Product(no, price);
		}
		else {
			file.get(taxCode);
			if (taxCode == 'H' || taxCode == 'P') {
				p_ipro = new TaxableProduct(no, price, taxCode);
			}
		}
		return p_ipro;
	}

	
}