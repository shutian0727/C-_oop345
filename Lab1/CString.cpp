#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CString.h"
#include <fstream>
int N = w1::CString::MAX;//external variable,it can only be found in source file.cpp

namespace w1{
	/*CString::CString() {
		int MAX = 0;
		char* my_string = nullptr;
	}*/
	CString::CString(const char* str)
	{
		if (str == NULL) {

			my_string[0] = '\0';
		}
		else {
			std::strncpy(my_string, str, MAX);
			N++;
			my_string[MAX] = '\0';
		}
	}

	void CString::display(std::ostream& os) const {

		os << my_string;
	}

	/*CString::~CString() {

	delete[] my_string;
	//my_string = nullptr;
	} */

	std::ostream& operator << (std::ostream& os, const CString& str)
	{
		
		str.display(os);
		return os;

	}
}

