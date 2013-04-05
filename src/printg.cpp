#include "include/printg.h"
#include "include/AdjacencyList.h" 
#include "include/DataStructure.h"

void printVertex(string vertex){
	cout << vertex << endl;
}

void printEdges(string vertexA, edge_<string> edge){
	cout << vertexA << " " << edge.getVertex() << endl;
}

void printg(GraphManipulator *gm){
	list<string> vertexs = gm->getVertexs();

	for (std::list<string>::iterator itVertexs = vertexs.begin(); 
				itVertexs != vertexs.end(); itVertexs++){

		list<edge_ <string>> edgesOf = gm->getEdges(*itVertexs);

		for (std::list<edge_ <string>>::iterator 
				itEdges = edgesOf.begin();
                                itEdges != edgesOf.end(); itEdges++){
			
			printEdges(*itVertexs,*itEdges);
						
		}		
	}
}


int main(void){
	AdjacencyList<string>* List = new AdjacencyList<string>();
        GraphManipulator* gm = new GraphManipulator(List);
        string teste1("1");
        string teste2("2");
        gm->addEdge(teste1,teste2,3);
	gm->addEdge(teste2,teste1,3);
	printg(gm);
}
