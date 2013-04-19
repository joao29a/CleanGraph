#ifndef DFS_H
#define DFS_H

#include "GraphManipulator.h"
#include "DataStructure.h"

class dfs{
private:
	int time;

protected:
	void DFS_visit(GraphManipulator*, vertex_<string>*);
	virtual void setInput_stamp(vertex_<string>*);
	virtual void setOutput_stamp(vertex_<string>*);

public:
	void DFS(GraphManipulator*);
	void print(GraphManipulator*);
};

#endif
