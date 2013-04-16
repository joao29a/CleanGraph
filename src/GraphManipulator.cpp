#include "include/DataStructure.h"
#include "include/GraphManipulator.h"
#include <iostream>

void GraphManipulator::addVertex(string vertexA){
	DS->addVertex(vertexA);
}

void GraphManipulator::addEdge(string vertexA, string vertexB, int weight){
	DS->addEdge(vertexA,vertexB,weight);
}

list<edge_ <string>> GraphManipulator::getEdges(vertex_<string> vertexA){
	return DS->getEdges(vertexA);
}

list<vertex_<string>*> GraphManipulator::getVertexs(){
	return DS->getVertexs();
}

void GraphManipulator::removeEdge(string vertexA,string vertexB){
	DS->removeEdge(vertexA,vertexB);
}

void GraphManipulator::setColor(vertex_<string> vertex,string color){
	DS->setColor(vertex,color);
}
