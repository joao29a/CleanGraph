#include "include/dfs.h"
#include <list>
#include <iostream>

void dfs::DFS(GraphManipulator* gm){
	list<vertex_<string>*> Vertexs = gm->getVertexs();
	list<vertex_<string>*>::iterator itVertexs;
	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
						itVertexs++){
		(*itVertexs)->setColor("white");
		(*itVertexs)->setFather("NULL");
	}
	time = 0;
	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
						itVertexs++){
		if ((*itVertexs)->getColor() == "white")
			DFS_visit(gm,(*itVertexs));	
	}
}

void dfs::DFS_visit(GraphManipulator* gm, vertex_<string>* u){
	time++;
	setInput_stamp(u);
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

void dfs::setInput_stamp(vertex_<string>* u){
	u->setInput(time);
}

void dfs::setOutput_stamp(vertex_<string>* u){
	u->setOutput(time);
}

void dfs::print(GraphManipulator* gm){
	list<vertex_<string>*> Vertexs = gm->getVertexs();
	list<vertex_<string>*>::iterator itVertexs;
	for (itVertexs = Vertexs.begin(); itVertexs != Vertexs.end();
						itVertexs++){
		cout << (*itVertexs)->getValue() << " -> " << 
				(*itVertexs)->getInput() << " | "
				<< (*itVertexs)->getOutput() <<
				endl;
	}
}
