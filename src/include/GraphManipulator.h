#ifndef GRAPHMANIPULATOR_H
#define GRAPHMANIPULATOR_H
#include "DataStructure.h"
#include <string>

using namespace std;

class GraphManipulator{
private:
	DataStructure<string>* DS;
public:
	GraphManipulator(DataStructure<string> *ds) { this->DS = ds; };
	void addVertex(string);
	void addEdge(string, string);
	bool hasEdge(string, string);
};

#endif
