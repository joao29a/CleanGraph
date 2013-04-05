#include "include/AdjacencyList.h"
#include <string>
#include "include/GraphManipulator.h"
#include <iostream>

int main(){
	AdjacencyList<string>* List = new AdjacencyList<string>();
	GraphManipulator* gm = new GraphManipulator(List);
	string teste1("1");
	string teste2("2");	
	gm->addEdge(teste1,teste2,3);
	gm->removeEdge(teste1,teste2);
	return 0;
}
