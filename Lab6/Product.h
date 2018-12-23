#ifndef W7_PRODUCT_H
#define W7_PRODUCT_H
#include "iProduct.h"


namespace w6 {

	class Product : public iProduct {

		int product_num_;
		double cost_;

	public:
		Product();
		Product(int product_num, double cost);
		virtual double getPrice() const;
		virtual void display(std::ostream& os) const;
	};
}

#endif