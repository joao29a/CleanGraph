#include "include/mst-prim.h"
#include "include/HeapTree.h"
#include <limits>

void prim::mstPrim(GraphManipulator* gm, vertex_<string>* v){
	list<vertex_<string>*> Vertexs = gm->getVertexs();
	list<vertex_<string>*>::iterator itVertexs;
	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end(); itVertexs++){
		(*itVertexs)->setKey(numeric_limits<int>::max());
		(*itVertexs)->setFather("NULL");
	}
	v->setKey(0);
	HeapTree<string>* Q = new HeapTree<string>();
	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end(); itVertexs++){
		Q->add(*(*itVertexs));
	}
	Q->heapMin();
	int total=0;
	while (!Q->empty()){
		vertex_<string> u = Q->extractMin();
		total+=u.getKey();
		list<edge_<string>> edges = gm->getEdges(u);
		list<edge_<string>>::iterator itEdges;
		for (itEdges = edges.begin(); itEdges != edges.end(); itEdges++){
			vertex_<string>* vertexAdj = 
				gm->getVertexAttributes((*itEdges).getVertex());
			if (Q->search((*vertexAdj)) && (*itEdges).getWeight() < vertexAdj->getKey()){
				(*vertexAdj).setFather(u.getValue());
				(*vertexAdj).setKey((*itEdges).getWeight());
				Q->refreshHeap((*vertexAdj));
				Q->heapMin();
			}
		}
	}
	cout << total << endl;
}
