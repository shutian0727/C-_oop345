// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Author:  Shutian Xu
// Date:    2018-08-31
// Updated by Cornel -- Changed the timing to nanoseconds and changed namespace
#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"
using namespace std;
namespace w2 {
	Text::Text(){}

	Text::Text(const std::string str) {
		// reading file using text file
		ifstream file(str);

		if (file.is_open()) {
			std::string line;
			while (!file.eof()) {
				getline(file, line);
				lineNo++;
	}
			strings = new string[lineNo];
			file.clear();
			file.seekg(0);
			for (size_t i = 0u; i < lineNo; i++)
			{
				getline(file, strings[i]);
			}
		}else {
			*this = Text();
		}
	}

	//Copy Constructor:
	Text::Text(const Text& text) {
        *this = text;
	}
    
	//Move Constructor:
	Text::Text(Text&& text) {
		//lineNo = 0;
		//delete[]strings;
		//strings = nullptr;
		//*this = std::move(text);
		this->lineNo = text.lineNo;
		//this->filename = text.filename;
		//this->filename.assign(text.filename);
		this->strings = text.strings;
		text.strings = nullptr;
	}

	//Copy Assingment:
	Text& Text::operator=(const Text& text) {
		if (this != &text) {
			this->lineNo = text.lineNo;
			//delete current object
			delete[] this->strings;
			//this->strings = nullptr;
			this->strings = new string[text.lineNo];
            //this->filename = text.filename;
			//this->filename.assign(text.filename);
			for (size_t i = 0u; i < lineNo; ++i)
			{
                strings[i] = text.strings[i];
				//this->strings[i].assign(text.strings[i]);
			}
		}
		return *this;
	}

	//Move Assignemnt:
	Text& Text::operator=(Text&& text) {
		if (this != &text) {
			this->lineNo = text.lineNo;
			//delete current object memory
			delete[] this->strings;
			//this->strings = nullptr;
			this->strings = text.strings;
            //this->filename = text.filename;
			//this->filename.assign(text.filename);
			//text.filename = '\0';
			text.strings = nullptr;
			text.lineNo = 0u;
		}
		return *this;
	}

	//Destructor:
	Text::~Text() {
		lineNo = 0u;
		delete[] strings;
		strings = nullptr;
	}

	size_t w2::Text::size() const {
		return lineNo;
	}
}

