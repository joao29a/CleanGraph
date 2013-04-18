#include "DataStructure.h"
#include "GraphManipulator.h"
#include <list>
#include <string>

class bfs{
public:
	void BFS(GraphManipulator*);
};

void bfs::BFS(GraphManipulator *gm){
	list<vertex_<string>*> Vertexs = gm->getVertexs();
	list<vertex_<string>*>::iterator itVertex;
	for (itVertex = Vertexs.begin(); itVertex != Vertexs.end(); itVertex++){
		(*itVertex)->setColor("white");
		(*itVertex)->setDistance(0);
	}
	itVertex = Vertexs.begin();
	(*itVertex)->setColor("gray");
	(*itVertex)->setDistance(0);
	
	list<vertex_<string>> Q;
	Q.push_back(*(*itVertex));
	while (!Q.empty()){
		vertex_<string> value = Q.front();
		Q.pop_front();
		list<edge_<string>> edges = gm->getEdges(value);
		list<edge_<string>>::iterator itEdges;
		for (itEdges = edges.begin(); itEdges!=edges.end(); itEdges++){
			list<vertex_<string>*> vertex = gm->getVertex((*itEdges).getVertex());
		}	
	}
}
