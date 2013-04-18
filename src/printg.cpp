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

int main(void){
	AdjacencyList<string>* List = new AdjacencyList<string>();
        GraphManipulator* gm = new GraphManipulator(List);
	FileIO io("graphs/ex1");
	io.fillStructureWithDataInFile(gm);
	printg(gm);
	bfs teste;
	teste.BFS(gm);
	return 0;
}
