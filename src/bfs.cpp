#include "include/bfs.h"
#include <list>

void BFS(GraphManipulator *gm){
	list<string> Vertex = gm->getVertexs();
	list<string>::iterator itVertex;
	for (itVertex = Vertex.begin(); itVertex != Vertex.end(); itVertex++){
		(*itVertex);
	}
}
