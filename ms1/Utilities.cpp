// homework: ms1
//file: Utilities.cpp
//Name: Shutian Xu
//Date: 11/9/2018
#include "Utilities.h"


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
	std::string str_ = str.substr(next_pos);
	size_t pos = str_.find(delimiter);

	if (pos != std::string::npos) {
		str_ = str_.substr(0, pos);
		next_pos += pos + 1;
		more = true;
	}
	else {
		more = false;
	}

	if (field_width < str_.length()) {
		field_width = str_.length();
	}
	return str_;
}

void Utilities::setDelimiter(const char d) {
	delimiter = d;
}

const char Utilities::getDelimiter() const {
	return delimiter;
}
