#include "include/printg.h"

void printVertex(vertex_<string> vertex){
	cout << "Vertex " << vertex.getValue() << ": ";
}

void printEdges(edge_<string> edge){
	cout << edge.getVertex() << " | ";
}

void printg(GraphManipulator *gm){
	list<vertex_<string>*> vertexs = gm->getVertexs();

	for (list<vertex_<string>*>::iterator itVertexs = vertexs.begin(); 
			itVertexs != vertexs.end(); itVertexs++){

		list<edge_ <string>> edgesOf = gm->getEdges(*(*itVertexs));

		printVertex(*(*itVertexs));	

		for (list<edge_ <string>>::iterator 
				itEdges = edgesOf.begin();
				itEdges != edgesOf.end(); itEdges++){

			printEdges(*itEdges);
		}
		cout << endl;
	}
}
