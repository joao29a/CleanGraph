#include "include/dfs.h"
#include <list>
#include <iostream>

void dfs::DFS(GraphManipulator* gm){

	Vertexs = gm->getVertexs();

	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
						itVertexs++){
		(*itVertexs)->setColor("white");
		(*itVertexs)->setFather("NULL");
	}

	time = 0;
	mainLoop(gm);
}

void dfs::DFS_visit(GraphManipulator* gm, vertex_<string>* u){
	time++;
	
	u->setInput(time);
	u->setColor("gray");
	
	list<edge_<string>> Edges = gm->getEdges((*u));
	list<edge_<string>>::iterator itEdges;

	for (itEdges = Edges.begin(); itEdges != Edges.end(); itEdges++){

		vertex_<string>* vertexAdj =
			gm->getVertexAttributes((*itEdges).getVertex());

		if (vertexAdj->getColor() == "white"){
			vertexAdj->setFather(u->getValue());
			DFS_visit(gm,vertexAdj);
		}

	}
	u->setColor("black");
	time++;
	setOutput_stamp(u);
}

void dfs::mainLoop(GraphManipulator* gm){

	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
						itVertexs++){

		if ((*itVertexs)->getColor() == "white"){
			DFS_visit(gm,(*itVertexs));	
		}

	}

}

void dfs::setOutput_stamp(vertex_<string>* u){
	u->setOutput(time);
}
