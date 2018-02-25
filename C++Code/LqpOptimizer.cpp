#include"LqpOptimizer.h"

LQP* LqpOptimizer::LogicalQueryplanOptimizer(LQP*& logical_query_plan)
{
		return logical_query_plan->FetchOptimizedQP();
}
