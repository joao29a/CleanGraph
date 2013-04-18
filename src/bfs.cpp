#include "include/bfs.h"
#include <list>
#include <iostream>

void bfs::BFS(GraphManipulator *gm, vertex_<string>* v){
	list<vertex_<string>*> Vertexs = gm->getVertexs();
	list<vertex_<string>*>::iterator itVertex;
	for (itVertex = Vertexs.begin(); itVertex != Vertexs.end(); itVertex++){
		(*itVertex)->setColor("white");
		(*itVertex)->setDistance(0);
		(*itVertex)->setFather("NULL");
	}

	(*v).setColor("gray");
	(*v).setDistance(0);
	(*v).setFather("NULL");	

	list<vertex_<string>*> Q;
	Q.push_back(v);
	while (!Q.empty()){
		vertex_<string>* value = Q.front();
		Q.pop_front();
		list<edge_<string>> edges = gm->getEdges((*value));
		list<edge_<string>>::iterator itEdges;
		for (itEdges = edges.begin(); itEdges!=edges.end(); itEdges++){
			vertex_<string>* vertexAdj = 
					gm->getVertexAttributes((*itEdges).getVertex());
			if (vertexAdj->getColor()=="white"){
				vertexAdj->setColor("gray");
				vertexAdj->setDistance(value->getDistance()+1);
				vertexAdj->setFather(value->getValue());
				Q.push_back(vertexAdj);
			}
		}
		value->setColor("black");
	}
	Vertexs = gm->getVertexs();
	cout << endl;
	for (itVertex = Vertexs.begin(); itVertex != Vertexs.end(); itVertex++){
		cout << "vertex " << (*itVertex)->getValue() << ": " << (*itVertex)->getDistance() 
				<< " " << (*itVertex)->getColor() << endl;
	}
}
