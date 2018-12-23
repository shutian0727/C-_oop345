// Name: Shutian Xu
// Student ID: 109783175
// Email: sxu61@myseneca.ca
// Date: 2018.09.27
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef PAIR_H
#define PAIR_H

template<typename A, typename B>
class Pair {
	A axes;
	B bear;
public:
	Pair() {}
	Pair(const A& axes_y, const B& bear_y) {
		axes = axes_y;
		bear = bear_y;
	}
	const A& getKey() const {
		return axes;
	}
	const B& getValue() const {
		return bear;
	}
};

#endif 