// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// Shutian Xu ID: 109783175
// 10/10/2018

#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//Update the main functions as per the specifications here

	Grades grades(argv[1]);
	//converts the grade to letter
	auto letter = [](double grade) {
		if (grade < 50)
			return Letter::F;
		else if (grade < 55)
			return Letter::D;
		else if (grade < 60)
			return Letter::Dp;
		else if (grade < 65)
			return Letter::C;
		else if (grade < 70)
			return Letter::Cp;
		else if (grade < 75)
			return Letter::B;
		else if (grade < 80)
			return Letter::Bp;
		else if (grade < 90)
			return Letter::A;
		else
			return Letter::Ap;

	};
	grades.displayGrades(ofs, letter);


	ofs.close();
	return 2;
}