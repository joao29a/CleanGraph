#include "include/printg.h"


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


