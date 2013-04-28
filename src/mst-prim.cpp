#include "include/mst-prim.h"
#include <limits>

void
 prim::initVertexs(list < vertex_ < string > *>Vertexs)
{

    list < vertex_ < string > *>::iterator itVertexs;

    for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
	 itVertexs++) {

	(*itVertexs)->setKey(numeric_limits < int >::max());
	(*itVertexs)->setFather("NULL");
    }

}

void prim::fillHeapTree(list < vertex_ < string > *>Vertexs,
			HeapTree < string > *Q)
{

    list < vertex_ < string > *>::iterator itVertexs;

    for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
	 itVertexs++) {
	Q->add(*(*itVertexs));
    }

}

void prim::mstPrim(GraphManipulator * gm, vertex_ < string > *root)
{
    list < vertex_ < string > *>Vertexs = gm->getVertexs();

    initVertexs(Vertexs);

    root->setKey(0);

    HeapTree < string > *Q = new HeapTree < string > ();

    fillHeapTree(Vertexs, Q);

    Q->heapMin();

    while (!Q->empty()) {

	vertex_ < string > u = Q->extractMin();
	list < edge_ < string >> edges = gm->getEdges(u);
	list < edge_ < string >>::iterator itEdges;

	for (itEdges = edges.begin(); itEdges != edges.end(); itEdges++) {
	    vertex_ < string > *vertexAdj =
		gm->getVertexAttributes((*itEdges).getVertex());

	    if (Q->search((*vertexAdj)) &&
		(*itEdges).getWeight() < vertexAdj->getKey()) {

		(*vertexAdj).setFather(u.getValue());
		(*vertexAdj).setKey((*itEdges).getWeight());

		Q->refreshHeap((*vertexAdj));
		Q->heapMin();
	    }
	}
    }
}

void prim::printMST(GraphManipulator * gm)
{

    list < vertex_ < string > *>Vertexs = gm->getVertexs();
    
    list < vertex_ < string > *>::iterator itVertexs;

    for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
	 itVertexs++) {

	if ((*itVertexs)->getFather() != "NULL")
	    cout << (*itVertexs)->getValue() << " " <<
		(*itVertexs)->getFather() << endl;
    }

}
