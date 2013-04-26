#include "include/printg.h"

void printVertex(vertex_ < string > vertex)
{
    cout << "Vertex " << vertex.getValue() << ": ";
}

void printEdge(edge_ < string > edge)
{
    cout << edge.getVertex() << " | ";
}

void printEdges(list < edge_ < string >> edgesOf)
{

    for (list < edge_ < string >>::iterator itEdges = edgesOf.begin();
	 itEdges != edgesOf.end(); itEdges++) {

	printEdge(*itEdges);
    }

}

void printMST(list < vertex_ < string > *>Vertexs)
{

    list < vertex_ < string > *>::iterator itVertexs;

    for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
	 itVertexs++) {

	if ((*itVertexs)->getFather() != "NULL")
	    cout << (*itVertexs)->getValue() << " " <<
		(*itVertexs)->getFather() << endl;
    }

}

void printg(GraphManipulator * gm)
{
    list < vertex_ < string > *>vertexs = gm->getVertexs();

    for (list < vertex_ < string > *>::iterator itVertexs =
	 vertexs.begin(); itVertexs != vertexs.end(); itVertexs++) {

	list < edge_ < string >> edgesOf = gm->getEdges(*(*itVertexs));

	printVertex(*(*itVertexs));

	printEdges(edgesOf);

	cout << endl;
    }

}
