#include "include/GraphManipulator.h"
#include <iostream>

void GraphManipulator::addVertex(string vertexA){
	DS->addEdge(vertexA,string("NULL"),-9999);
}

void GraphManipulator::addEdge(string vertexA, string vertexB, int weight){
	DS->addEdge(vertexA,vertexB,weight);
}

list<edge_ <string>> GraphManipulator::getEdges(string vertexA){
	return DS->getEdges(vertexA);
}

list<string> GraphManipulator::getVertexs(){
	return DS->getVertexs();
}

void GraphManipulator::removeEdge(string vertexA,string vertexB){
	DS->removeEdge(vertexA,vertexB);
}
