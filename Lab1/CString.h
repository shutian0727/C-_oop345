// Shutian Xu //
// 109783175 //
// OOP345 Lab_01 //

#ifndef CSTRING_H
#define CSTRING_H
#include <iostream>
#include <cstring>
#include <fstream>
 

namespace w1
{	
	class CString
	{
	public:
		static const int MAX = 3;
		CString(const char* str);
		void display(std::ostream& os) const;
		//~CString();
	private:
		char my_string[4];
                char* my_string[4];
	};


	std::ostream& operator<< (std::ostream& os, const CString& str);

}


#endif  

