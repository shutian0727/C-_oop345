// Workshop 5 - Lambda Expression
// Letter.h
// Chris Szalwinski & Dr. Elliott Coleshill
// Shutian Xu ID: 109783175
// 10/10/2018#

#ifndef _LETTER_H
#define _LETTER_H
#include <iostream>
#include <string>
using namespace std;
namespace sict {

	enum class Letter { Ap, A, B, Bp, C, Cp, D, Dp, F };
	//std::string str = "";

	template<typename T>
	//convert() function will return "A+" or "A" and any other grades
	string convert(const T& grd) {
		std::string str = "";
		switch (grd) {
		case Letter::Ap:
			str = "A+";
			break;
		case Letter::A:
			str = "A";
			break;
		case Letter::Bp:
			str = "B+";
			break;
		case Letter::B:
			str = "B";
			break;
		case Letter::Cp:
			str = "C+";
			break;
		case Letter::C:
			str = "C";
			break;
		case Letter::Dp:
			str = "D+";
			break;
		case Letter::D:
			str = "D";
			break;
		case Letter::F:
			str = "F";
			break;
		default:
			str = "";
			break;
		}
		return str.c_str();
	}


}

#endif