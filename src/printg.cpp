#include "include/FileIO.h"
#include "include/printg.h"
#include "include/AdjacencyList.h" 
#include "include/DataStructure.h"
#include <string>
#include "include/bfs.h"
#include "include/mst-prim.h"

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
	string bfsearch = "bfs";
	string mstree = "mst";
	while (argv[1]==bfsearch){	
		FileIO io(argv[2]);
		string beginVertex = io.fillStructureWithDataInFile(gm,"oriented");
		bfs a;
		a.BFS(gm,gm->getVertexAttributes(beginVertex));
		break;
	}
	while (argv[1]==mstree){
		FileIO io(argv[2]);
		string beginVertex = io.fillStructureWithDataInFile(gm,"notOriented");
		prim a;
		a.mstPrim(gm,gm->getVertexAttributes(beginVertex));
		break;
	}
	return 0;
}
