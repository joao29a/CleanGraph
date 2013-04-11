#include "include/FileIO.h"
#include "include/printg.h"
#include "include/AdjacencyList.h" 
#include "include/DataStructure.h"

using namespace std;

/*void printVertex(string vertex){
	cout << "Vertex " << vertex << ": ";
}

void printEdges(string vertexA, edge_<string> edge){
	cout << edge.getVertex() << " | ";
}

void printg(GraphManipulator *gm){
	list<string> vertexs = gm->getVertexs();

	for (list<string>::iterator itVertexs = vertexs.begin(); 
				itVertexs != vertexs.end(); itVertexs++){

		list<edge_ <string>> edgesOf = gm->getEdges(*itVertexs);
		
		printVertex(*itVertexs);	
	
		for (list<edge_ <string>>::iterator 
				itEdges = edgesOf.begin();
                                itEdges != edgesOf.end(); itEdges++){

			printEdges(*itVertexs,*itEdges);
		}
		cout << endl;
	}
}*/


int main(void){
	AdjacencyList<string>* List = new AdjacencyList<string>();
        /*GraphManipulator* gm = new GraphManipulator(List);
	FileIO io("graphs/ex1");
	io.fillStructureWithDataInFile(gm);
	printg(gm);*/
}
