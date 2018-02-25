//Program creates a simple logical query plan without subqueries
#ifndef _LQP_H
#define _LQP_H
#include <vector>
#include "Processing.h"
#include "TupleOperations.h"
#include "QueryPlanConstructor.h"
#include "TableProcessing.h"
#include "SendRelation.h"


enum OPtype {SELECT_OP, PROJECT, ORDERBY, VECTORPRODUCT,
						Optimum_PROJECT_S_PRODUCT, //Optimized (Single table)Product Followed by Project - A simple "select */a,b,c from table" case
						Optimum_PROJECT_S_PRODUCT_SELECT, //select */a,b,c from <tblename> where <condition>
						Optimum_PROJECT_M_PRODUCT, // No Condition, More than one table involved
						Optimum_PROJECT_M_PRODUCT_SELECT
						};

class LQP
{
		private:
				bool isUnique;
				vector<MyColumn> order_BY;
				SendRelation sendRelation;
				OPtype operationType;
				OrderOP orderByOp;
				ProjectOP projectOp;
				SelectOP selectOp;
				JOINOP productOp;
				QueryPlanConstructor* construct_QP;
				LQP* left_LogicalQP;
				LQP* right_LogicalQP;
		public:
				LQP();
				LQP(LQP*& left, LQP *&right);
				void Add_Left_LPQ(LQP*& lp);
				void Add_Right_LPQ(LQP*& rp);
				static LQP* CreateSelectQueryPlan(SelectOP selectop);
				static LQP* CreateProjectQueryPlan(ProjectOP projectop);
				static LQP* CreateJoinQueryPlan(JOINOP joinop);
				static LQP* CreateProjSelJoinQueryPlan(bool isDistinct, ProjectOP projectop, SelectOP& selectop, JOINOP joinop, vector<MyColumn> orderBy);
				static LQP* CreateProjJoinQueryPlan(bool isDistinct, ProjectOP projectop, JOINOP joinop, vector<MyColumn> orderBy);
				LQP* FetchOptimizedQP();
				SendRelation Execute();
				void operator delete(void *p);
	};
#endif
