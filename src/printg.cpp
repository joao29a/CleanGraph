#include "include/FileIO.h"
#include "include/printg.h"
#include "include/AdjacencyList.h" 
#include "include/DataStructure.h"
#include <string>
#include "include/bfs.h"

using namespace std;

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

int main(int argc, char *argv[]){
	AdjacencyList<string>* List = new AdjacencyList<string>();
	GraphManipulator* gm = new GraphManipulator(List);
	for (int i = 2; i < argc; i++){
		FileIO io(argv[i]);
		string beginVertex = io.fillStructureWithDataInFile(gm);
		bfs a;
		a.BFS(gm,gm->getVertexAttributes(beginVertex));
	}
	return 0;
}
