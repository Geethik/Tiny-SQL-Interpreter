//Program to construct the Logical query plan
#ifndef _QueryPlanConstructor_H
#define _QueryPlanConstructor_H
#include <algorithm>
#include "Block.h"
#include "Config.h"
#include "Disk.h"
#include "Field.h"
#include "MainMemory.h"
#include "Relation.h"
#include "Schema.h"
#include "SchemaManager.h"
#include "Tuple.h"
#include "SendRelation.h"
#include "Processing.h"
#include "TupleOperations.h"
#include "TableProcessing.h"
#include "TupleProcessing.h"

enum IDENTIFY_LEAF {TERMINAL = 1, NON_TERMINAL}; // all terminals are leaf and non-terminal are non leaf
class QueryPlanConstructor
{
private:
		SendRelation sendRelation;
		IDENTIFY_LEAF type;
		QueryPlanConstructor* from_left_QP;
		QueryPlanConstructor* from_right_QP;
		static int saveToDB;
public:
		QueryPlanConstructor(SendRelation send_reln);
		QueryPlanConstructor(QueryPlanConstructor*& left_QP, QueryPlanConstructor*& right_QP);
		SendRelation Compute();
		static QueryPlanConstructor* Create_optimum_QP(vector<string> from_list);
		void operator delete(void *pointer);
		static void set_num_SaveCount(int count);
	  static int get_num_SaveCount();
};

#endif
