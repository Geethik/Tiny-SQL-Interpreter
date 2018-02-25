//Generates Optimized Query plan.
#include "GeneratorLQP.h"

LQP* GeneratorLQP::
GenerateLQPlan(vector<MyColumn> project_list, vector<string> from_list, Search*& search_cond)
{
			JOINOP prodOp_obj(from_list);
			LQP *lp_crossproduct = LQP::CreateJoinQueryPlan(prodOp_obj);
			LQP *lp_select = NULL;
			if(search_cond != NULL)
			{
					SelectOP SelectOp_obj(search_cond);
					LQP *lp_select = LQP::CreateSelectQueryPlan(SelectOp_obj);
					lp_select->Add_Left_LPQ(lp_crossproduct);
			}

			ProjectOP projectOp_obj(project_list);
			LQP *lp_Project = LQP::CreateProjectQueryPlan(projectOp_obj);

			if(search_cond != NULL)
			{
				lp_Project->Add_Left_LPQ(lp_select);
			}
			else
			{
				lp_Project->Add_Left_LPQ(lp_crossproduct);
			}
			return lp_Project; // final logical plan
}

LQP* GeneratorLQP::
GenerateOptimizedLQPlan(bool isUnique, vector<MyColumn> project_list, vector<string> from_list, Search*& search_cond, vector<MyColumn> orderby_list)
{
			LQP* Optimized_QP;
			JOINOP prodOp_obj(from_list); //Create a product operation
			// cout << "Created JoinOP" << endl;
			ProjectOP projectOp_obj(project_list);
			// projectOp_obj.fetchcolumnString();
			// cout << "Created ProjectOP" << endl;
			if(search_cond != NULL)
			{
				SelectOP SelectOp_obj(search_cond);// select condition
				// cout << "Created SelectOP" << endl;
				// cout << isUnique << endl;
				Optimized_QP = LQP::CreateProjSelJoinQueryPlan(isUnique, projectOp_obj, SelectOp_obj, prodOp_obj, orderby_list);
				// cout << "Created Optimized_QP" << endl;
			}
			else {
				// cout << isUnique << endl;
				Optimized_QP = LQP::CreateProjJoinQueryPlan(isUnique, projectOp_obj, prodOp_obj, orderby_list);
			}
			return Optimized_QP; //return optimised LQP
}
