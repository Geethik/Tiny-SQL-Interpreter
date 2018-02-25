//Generates Optimized Query plan.
#ifndef _GeneratorLQP_H
#define _GeneratorLQP_H
#include <cstdlib>
#include "LQP.h"
#include "finder.h"
#include "Processing.h"

class GeneratorLQP
{
	public:
		static LQP* GenerateLQPlan(vector<MyColumn> project_list, vector<string> from_list, Search*& search_cond);
		static LQP* GenerateOptimizedLQPlan(bool isUnique, vector<MyColumn> project_list, vector<string> from_list, Search*& search_cond, vector<MyColumn> orderby_list);
		//static LQP* GenerateLQPlan(vector<MyColumn> project_list, vector<string> from_list);
};
#endif
