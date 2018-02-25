//Evaluation of Logical operators AND, OR, NOT in the search condition WHERE.
#ifndef _FINDER_H
#define _FINDER_H
#include <cstdlib>
#include <string>
#include <iostream>
#include "Comparator.h"
// #include "DB_config.h"

enum Finder_Operator {find_AND = 1, find_OR, find_NOT, find_SELF};


class Search {
	private:
		Finder_Operator finder_operator;
		Compare* compare_predicate;
		Search* search_right;
		Search* search_left;
	public:
		Search(Search*& search_left, string f_opt, Search*& search_right);
		Search(Compare*& myvalue);
		bool Compute();
		void operator delete(void *pointer);
};
#endif
