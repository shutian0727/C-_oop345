// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Author:  Shutian Xu
// Date:    2018-08-22

#include <iostream>
#include <fstream>
#include "process.h"
extern int N;

int main(int argc, char* argv[]) {
	
	std::ofstream ofs("Lab1Output.txt");
	ofs << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		ofs << argv[i] << ' ';
	}
	if (argc < 2) {
		ofs << "\nInsufficient number of arguments\n";
		return 1;
	}
	    //ofs << std::endl;
		ofs << "\nMaximum number of characters stored : " << N << std::endl;

		for (int i = 1; i < argc; i++) {
			 process(argv[i], ofs);
		}
		int WaitKey;
		std::cin >> WaitKey;

		ofs.close();
		return 0;
	}

