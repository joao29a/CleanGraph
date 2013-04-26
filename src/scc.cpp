#include "include/scc.h"
#include "include/dfs.h"
#include "include/AdjacencyList.h"
#include "include/printg.h"
#include <list>
#include <iostream>

void scc::stronglyComponent(GraphManipulator* gm){
	AdjacencyList<string>* List2 = new AdjacencyList<string>();
	GraphManipulator* gmT = new GraphManipulator(List2);
	
	dfs dfsObj;
	dfsObj.DFS(gm);
	
	scc obj;
	obj.transposed(gm,gmT);
	obj.DFS(gmT);
	obj.outputTree(gmT);
}

void scc::mainLoop(GraphManipulator* gm){
	for (itOrdVertex = vertexOrd.begin(); itOrdVertex != vertexOrd.end();
					itOrdVertex++){
		vertex_<string>* vertex = 
				gm->getVertexAttributes((*itOrdVertex).getValue());

		if (vertex->getColor() == "white"){
			DFS_visit(gm,vertex);
		}

	}
}

void scc::setOutput_stamp(vertex_<string>* u){
	u->setOutput(time);
	queue.push_back(*u);
}

void scc::transposed(GraphManipulator* gm, GraphManipulator* gmT){
	Vertexs = gm->getVertexs();

	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
						itVertexs++){
		
		vertexOrd.push_back(*(*itVertexs));
		gmT->addVertex((*itVertexs)->getValue());
		list<edge_<string>> Edges = gm->getEdges(*(*itVertexs));
		list<edge_<string>>::iterator itEdges;

		for (itEdges = Edges.begin(); itEdges != Edges.end();
						itEdges++){
			gmT->addEdge((*itEdges).getVertex(),
					(*itVertexs)->getValue(),
					(*itEdges).getWeight());
		}

	}

	vertexOrd.sort(sortOutput);
}

bool sortOutput(const vertex_<string> &otherA, const vertex_<string> &otherB){
	return (otherA.getOutput() > otherB.getOutput());	
}

void scc::outputTree(GraphManipulator* gm){
	list<vertex_<string>>::iterator it;

	for (it=queue.begin();it!=queue.end();it++){
		cout << it->getValue() << " ";
		if (it->getFather() == "NULL")
			cout << endl;
		
	}
}
