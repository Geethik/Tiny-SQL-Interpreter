//Handles all scenarios involving comparison operators
#ifndef _COMPARATOR_H
#define _COMPARATOR_H
#include <cstdlib>
#include <iostream> // For debugging
#include "Expressions.h"
enum Comparator_Operator {comp_less, comp_greater, comp_equal, comp_self};//< , > , ==

class Compare
{
private:
	bool myvalue;
	Comparator_Operator c_opt;
	Expressions* exp_left;
	Expressions* exp_right;
public:
	Compare(bool value);
	Compare(Expressions*& expLeft, string c_opt, Expressions*& expRight);
	bool Compute();
	void operator delete(void *pointer);
};
#endif

