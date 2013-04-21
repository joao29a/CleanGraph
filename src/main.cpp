#include "include/FileIO.h"
#include "include/AdjacencyList.h" 
#include "include/bfs.h"
#include "include/mst-prim.h"
#include "include/ts.h"
#include "include/scc.h"

int main(int argc, char *argv[]){
	AdjacencyList<string>* List = new AdjacencyList<string>();
	GraphManipulator* gm = new GraphManipulator(List);
	string bfsearch = "bfs";
	string tsort = "ts";
	string sccomponent = "scc";
	string mstree = "mst";
	FileIO io(argv[2]);
	if (argv[1]==mstree){
		string beginVertex = io.fillStructureWithDataInFile(gm,"notOriented");
		prim a;
		a.mstPrim(gm,gm->getVertexAttributes(beginVertex));
	}
	string beginVertex = io.fillStructureWithDataInFile(gm,"oriented");
	if (argv[1]==bfsearch){	
		bfs a;
		a.BFS(gm,gm->getVertexAttributes(beginVertex));
	}
	else if (argv[1]==tsort){
		list<vertex_<string>> saida;
		list<vertex_<string>>::iterator itSaida;
		ts a;
		saida = a.topologicalSort(gm);
		for (itSaida = saida.begin(); itSaida != saida.end(); itSaida++){
			cout << (*itSaida).getValue() << endl;
		}
	}
	else if (argv[1]==sccomponent){
		scc a;
		a.stronglyComponent(gm);	
	}
	return 0;
}
