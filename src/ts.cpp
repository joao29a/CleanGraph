#include "include/ts.h"
#include <iostream>

list<vertex_<string>> ts::topologicalSort(GraphManipulator* gm){
	dfs* obj = new ts();
	obj->DFS(gm);
	if (listVertex.empty())
		cout << "vazio";
	return listVertex;
}

void ts::setOutput_stamp(vertex_<string>* u){
	u->setOutput(time);
	listVertex.push_front(*u);
	//print();
}

void ts::print(){
	for (itList = listVertex.begin(); itList != listVertex.end(); itList++){
		cout << (*itList).getValue() << " ";
	}
}
