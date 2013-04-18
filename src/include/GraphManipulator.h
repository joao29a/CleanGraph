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
	void addEdge(string, string, int);
	void removeEdge(string,string);
	list<edge_<string>> getEdges(vertex_<string>);
	list<vertex_<string>*> getVertexs();
	list<vertex_<string>*> getVertex(string);
};

#endif
