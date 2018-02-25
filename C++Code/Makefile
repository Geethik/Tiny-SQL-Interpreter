all: Tiny_SQL

Tiny_SQL: InputFileParser.o QueryPlanConstructor.o Analyzer.o LexicalAnalyzer.o SqlProcessor.o LQP.o Processing.o GeneratorLQP.o LqpOptimizer.o Comparator.o Expressions.o TupleOperations.o TupleProcessing.o finder.o SqlToken.o TableProcessing.o StorageManager.o
	g++ -g -o Tiny_SQL InputFileParser.o QueryPlanConstructor.o Analyzer.o LexicalAnalyzer.o SqlProcessor.o LQP.o Processing.o GeneratorLQP.o LqpOptimizer.o Comparator.o Expressions.o TupleOperations.o TupleProcessing.o finder.o SqlToken.o TableProcessing.o StorageManager.o Tiny_SQL.cpp

InputFileParser.o: InputFileParser.h
	g++ -g -c -std=c++11 InputFileParser.cpp

QueryPlanConstructor.o: QueryPlanConstructor.h Block.h Config.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h SendRelation.h Processing.h TupleOperations.h TableProcessing.h TupleProcessing.h
	g++ -g -c -std=c++11 QueryPlanConstructor.cpp

Analyzer.o: Analyzer.h Block.h Config.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h DB_Config.h LexicalAnalyzer.h SqlProcessor.h LQP.h Processing.h GeneratorLQP.h LqpOptimizer.h
	g++ -g -c -std=c++11 Analyzer.cpp

LexicalAnalyzer.o: LexicalAnalyzer.h SqlToken.h MyKeyWords.h
	g++ -g -c -std=c++11 LexicalAnalyzer.cpp

SqlProcessor.o: SqlProcessor.h Block.h Config.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h LQP.h
	g++ -g -c -std=c++11 SqlProcessor.cpp

LQP.o: LQP.h Processing.h TupleOperations.h QueryPlanConstructor.h TableProcessing.h SendRelation.h
	g++ -g -c -std=c++11 LQP.cpp

Processing.o: Processing.h TupleOperations.h finder.h DB_Config.h
	g++ -g -c -std=c++11 Processing.cpp

GeneratorLQP.o: GeneratorLQP.h LQP.h finder.h Processing.h
	g++ -g -c -std=c++11 GeneratorLQP.cpp

LqpOptimizer.o: LqpOptimizer.h LQP.h
	g++ -g -c -std=c++11 LqpOptimizer.cpp

Comparator.o: Comparator.h Expressions.h
	g++ -g -c -std=c++11 Comparator.cpp

Expressions.o: Expressions.h TupleOperations.h Block.h Config.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h
	g++ -g -c -std=c++11 Expressions.cpp

TupleOperations.o: TupleOperations.h Block.h Config.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h Processing.h DB_Config.h SendRelation.h TableProcessing.h TupleProcessing.h
	g++ -g -c -std=c++11 TupleOperations.cpp

TupleProcessing.o: TupleProcessing.h Block.h Config.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h DB_Config.h
	g++ -g -c -std=c++11 TupleProcessing.cpp

finder.o: finder.h Comparator.h
	g++ -g -c -std=c++11 finder.cpp

SqlToken.o: SqlToken.h
	g++ -g -c -std=c++11 SqlToken.cpp

TableProcessing.o: TableProcessing.h
	g++ -g -c -std=c++11 TableProcessing.cpp

StorageManager.o: Block.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h Config.h
	g++ -g -c -std=c++11 StorageManager.cpp

clean:
	rm *.o Tiny_SQL

#TestStorageManager: StorageManager.o
#	g++ -o TestStorageManager StorageManager.o TestStorageManager.cpp
#
#StorageManager.o: Block.h Disk.h Field.h MainMemory.h Relation.h Schema.h SchemaManager.h Tuple.h Config.h
#	g++ -c StorageManager.cpp
#
#clean:
#	rm *.o TestStorageManager
