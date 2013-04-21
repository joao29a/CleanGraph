#ifndef TS_H
#define TS_H

#include "dfs.h"
#include "DataStructure.h"
#include "GraphManipulator.h"
#include <list>

class ts: public dfs{
private:
	list<vertex_<string>> listVertex;
	list<vertex_<string>>::iterator itList;
protected:
	void setOutput_stamp(vertex_<string>*);
public:
	list<vertex_<string>> topologicalSort(GraphManipulator*);
};

#endif
