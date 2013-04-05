
#include "include/GraphManipulator.h"
#include <iostream>

void GraphManipulator::addVertex(string vertexA){
	return DS->addEdge(vertexA,"NULL");
}

void GraphManipulator::addEdge(string vertexA, string vertexB){
	return DS->addEdge(vertexA,vertexB);
}

bool GraphManipulator::hasEdge(string vertexA, string vertexB){
	return DS->search(vertexA,vertexB);
}


