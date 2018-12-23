//Utility.cpp
//Name: Shutian Xu
//ID: 109783175
//Date:11/16/2018

#include "Utilities.h"

using namespace std;

char Utilities::delimiter = ' ';

Utilities::Utilities() {
	field_width = 1;
}

void Utilities::setFieldWidth(size_t fw) {
	field_width = fw;
}

size_t Utilities::getFieldWidth() const {
	return field_width;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	next_pos = next_pos == 0 ? 0 : next_pos + 1;
	size_t pos = next_pos;
	next_pos = str.find(delimiter, pos);
	if (next_pos == std::string::npos) { 
		more = false;
	}
	else { 
		more = true; 
	}

	std::string token = str.substr(pos, next_pos - pos);

	if (token.empty()) {
		more = false;
	}

	if (field_width < token.length()) {
		field_width = token.length();
	}

	return token;

}

void Utilities::setDelimiter(const char d) {
	delimiter = d;
}

const char Utilities::getDelimiter() const {
	return delimiter;
}