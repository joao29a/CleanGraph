#include "include/FileIO.h"
#include "include/AdjacencyList.h"
#include "include/bfs.h"
#include "include/mst-prim.h"
#include "include/ts.h"
#include "include/scc.h"
#include <cstring>

#define bfsearch "bfs"
#define tsort "ts"
#define sccomponent "scc"
#define mstree "mst"

int main(int argc, char *argv[])
{

    AdjacencyList < string > *List = new AdjacencyList < string > ();
    GraphManipulator *gm = new GraphManipulator(List);

    FileIO io(argv[2]);
    if (strcmp(argv[1], mstree) == 0) {

	string beginVertex =
	    io.fillStructureWithDataInFile(gm, "notOriented");
	prim primAlgorithm;
        primAlgorithm.mstPrim(gm, gm->getVertexAttributes(beginVertex));
	primAlgorithm.printMST(gm);

	return 0;
    }

    string beginVertex = io.fillStructureWithDataInFile(gm, "oriented");

    if (strcmp(argv[1], bfsearch) == 0) {

	bfs obj;
	obj.BFS(gm, gm->getVertexAttributes(beginVertex));

    } else if (strcmp(argv[1], tsort) == 0) {

	list < vertex_ < string >> saida;
	list < vertex_ < string >>::iterator itSaida;
	ts obj;
	saida = obj.topologicalSort(gm);

	for (itSaida = saida.begin(); itSaida != saida.end(); itSaida++) {
	    cout << (*itSaida).getValue() << endl;
	}

    } else if (strcmp(argv[1], sccomponent) == 0) {

	scc obj;
	obj.stronglyComponent(gm);

    }
    return 0;
}
