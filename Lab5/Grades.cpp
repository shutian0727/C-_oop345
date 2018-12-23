// Workshop 5 - Lambda Expression
// Grades.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 10/10/2018
#include <iostream>
#include <fstream>
#include "Grades.h"
using namespace std;

namespace sict {

	Grades::Grades(const char* file) {
		// read infile
		std::ifstream is;
		std::string line;
		unsigned count = 0;//count the number of lines

						   //try {
		is.open(file);
		if (is.fail()) {
			throw "Failed to open the file: " + string(file);
		}
		cout << 99999999999 << endl;

		//! counts how many entries there are in the file
		// file is not at the end, it stil has sth to show
		while (!is.eof()) {
			cout << "ok";
			getline(is, line);
			count++;
		}
		is.clear();
		//! return to the begin of fstream
		is.seekg(0, std::ios::beg);

		//! memory allocation for grades and students
		counter = count;
		grades = new double[counter];
		student = new string[counter];

		//! read student numbers and grades
		//while (is.good()) {

		for (int i = 0; i < counter; i++) {
			// read student number
			getline(is, line, '\n');
			//get convert student number from string to int//12344 54 1234
			student[i] = line.substr(0, line.find(' '));
			line.erase(0, (line.find(' ') + 1));
			// get convert student grade from string to double
			grades[i] = stod(line.substr(0));
		}
	}

	Grades::~Grades() {
		counter = 0;

		delete[] student;
		student = nullptr;

		delete[] grades;
		grades = nullptr;
	}

}