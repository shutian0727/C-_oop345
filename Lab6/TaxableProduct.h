#ifndef W7_TAXABLEPRODUCT_H
#define W7_TAXABLEPRODUCT_H
#include "Product.h"
#include "iProduct.h"
using namespace std;

namespace w6 {

	class TaxableProduct : public Product {
		enum class tax{NONE,HST,PST};
		tax taxable_status_;
		static const double taxRate[3];

	public:
		
		TaxableProduct(int product_number, double cost, char taxcode);
		virtual double getPrice() const;
		virtual void display(std::ostream& os) const;
		//static double getTaxRate(char Code) { return (Code == 'H') ? taxRate[1] : taxRate[2]; };
	};

}


#endif
