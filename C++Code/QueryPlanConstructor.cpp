//Program to construct the Logical query plan
#include "QueryPlanConstructor.h"
#include "SendRelation.h"

extern MainMemory mem;
extern Disk disk;
extern SchemaManager schema_manager;
int QueryPlanConstructor::saveToDB = 0;
SendRelation ComputeJoinOP(SendRelation s, SendRelation r);
QueryPlanConstructor::QueryPlanConstructor(SendRelation send_reln)
{
		sendRelation = send_reln;
		type = TERMINAL;
		from_left_QP = NULL;
		from_right_QP = NULL;
}
QueryPlanConstructor::QueryPlanConstructor(QueryPlanConstructor*& left_QP, QueryPlanConstructor*& right_QP)
{
		from_left_QP = left_QP;
		from_right_QP = right_QP;
		type = NON_TERMINAL;
}
SendRelation QueryPlanConstructor::Compute()
{
		SendRelation return_relnrn_value;
		switch(type)
		{
				case NON_TERMINAL:
						bool save;
						save = false;
						return_relnrn_value = ComputeJoinOP(from_left_QP->Compute(),from_right_QP->Compute());
						sendRelation = return_relnrn_value;
						saveToDB--;
						break;
				case TERMINAL:
						return_relnrn_value = sendRelation;
						break;
		}
		return return_relnrn_value;
}

void QueryPlanConstructor::operator delete(void *pointer)
{
}

SendRelation ComputeJoinOP(SendRelation s, SendRelation r)
{
		  bool save = false;
			if(QueryPlanConstructor::get_num_SaveCount()>0)
				save = true;
			SendRelation send_reln;
			string tempTable = TableProcessing::rand_table();
			vector<Tuple> tuples = TScan::GetProd(s.relation_name, r.relation_name, tempTable, save);
			send_reln.relation_name = tempTable;
			send_reln.marked_For_Delete = true;
			send_reln.tuples = tuples;
			return send_reln;
}

QueryPlanConstructor* construct_QP = NULL;
QueryPlanConstructor* from_child_QP = NULL;
vector<string> global_table_list;

void Parse_Table_Value()
{
		string tabname = global_table_list.back();
		SendRelation return_reln;
		return_reln.marked_For_Delete = false;
		return_reln.relation_name = tabname;
		from_child_QP = new QueryPlanConstructor(return_reln);
		global_table_list.pop_back();
}
void Parse_From_List()
{
		Parse_Table_Value();
		construct_QP = from_child_QP;
		if(global_table_list.size() != 0)
		{
			QueryPlanConstructor* left = construct_QP;
			Parse_From_List();
			QueryPlanConstructor* right = construct_QP;
			construct_QP = new QueryPlanConstructor(left, right);
		}
}
QueryPlanConstructor* QueryPlanConstructor::Create_optimum_QP(vector<string> from_list)
{
		QueryPlanConstructor* qp_return;
		vector<string> mylist = from_list;
		sort(mylist.begin(), mylist.end(), Size_Comparison);
		global_table_list = mylist;
		Parse_From_List();
		qp_return = construct_QP;
		construct_QP = NULL;
		global_table_list.clear();
		return qp_return;
}

void QueryPlanConstructor::set_num_SaveCount(int count)
{
		saveToDB = count;
}

int QueryPlanConstructor::get_num_SaveCount()
{
		return saveToDB;
}
