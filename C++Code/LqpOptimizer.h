#ifndef _LqpOptimizer_H
#define _LqpOptimizer_H
#include<cstdlib>
#include "LQP.h"

class LqpOptimizer
{
	public:
		static LQP* LogicalQueryplanOptimizer(LQP*& lqp);
};

#endif
