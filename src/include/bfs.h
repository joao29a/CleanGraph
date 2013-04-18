#include "DataStructure.h"
#include "GraphManipulator.h"
#include <list>
#include <string>

class bfs{
public:
	void BFS(GraphManipulator*);
};

void bfs::BFS(GraphManipulator *gm){
	vertex_<string>* v;
	list<vertex_<string>*> Vertexs = gm->getVertexs();
	list<vertex_<string>*>::iterator itVertex;
	for (itVertex = Vertexs.begin(); itVertex != Vertexs.end(); itVertex++){
		(*itVertex)->setColor("white");
		(*itVertex)->setDistance(0);
	}
	v = *(Vertexs.begin());
	(*v).setColor("gray");
	(*v).setDistance(0);
	
	list<vertex_<string>> Q;
	Q.push_back((*v));
	while (!Q.empty()){
		vertex_<string> value = Q.front();
		Q.pop_front();
		list<edge_<string>> edges = gm->getEdges(value);
		list<edge_<string>>::iterator itEdges;
		for (itEdges = edges.begin(); itEdges!=edges.end(); itEdges++){
			vertex_<string>* vertexAdj = 
					gm->getVertexAttributes((*itEdges).getVertex());
		}	
	}
}
