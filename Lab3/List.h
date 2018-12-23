// Name: Shutian Xu
// Student ID: 109783175
// Email: sxu61@myseneca.ca
// Date: 2018.09.27
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LIST_H
#define LIST_H

template<typename T, int N>
class List { T array[N];
	size_t No;
	T Tyler;
public:
	List() { No = 0u; }
	size_t size() const{
		return No;
	}
	const T& operator[](int index) const {
		if (index >= 0 && static_cast<unsigned int>(index)<size())
			return array[index];
		else
			return Tyler;
	}
	void operator+=(const T& text) {
		if (No<N)
			array[No++] = text;
	}
};

#endif 