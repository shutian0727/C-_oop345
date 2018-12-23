#include <iostream>
#include "process.h"
#include "CString.h"

using namespace std;


	void process(char* string, std::ostream& os)
	{
		static int count = 0;
		w1::CString object(string);
		os << count++ << ": " << object << endl;

	}

