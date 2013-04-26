#include "include/bfs.h"
#include <list>
#include <iostream>

void bfs::initVertexs(list<vertex_<string>*> Vertexs){
	
	list<vertex_<string>*>::iterator itVertex;

        for (itVertex = Vertexs.begin(); itVertex != Vertexs.end(); itVertex++){
                (*itVertex)->setColor("white");
                (*itVertex)->setDistance(0);
                (*itVertex)->setFather("NULL");
        }
	
}

void bfs::markAdjacents(GraphManipulator *gm,
			list<edge_<string>> edges,
			vertex_<string>* vertexRemoved,
			list<vertex_<string>*>* Q){

	list<edge_<string>>::iterator itEdges;
        for (itEdges = edges.begin(); itEdges!=edges.end(); itEdges++){

             vertex_<string>* vertexAdj = 
				gm->getVertexAttributes((*itEdges).getVertex());

        	if (vertexAdj->getColor()=="white"){
                	vertexAdj->setColor("gray");
                        vertexAdj->setDistance(vertexRemoved->getDistance()+1);
                        vertexAdj->setFather(vertexRemoved->getValue());
                        Q->push_back(vertexAdj);
                }
        }

}

void bfs::BFS(GraphManipulator *gm, vertex_<string>* root){
	list<vertex_<string>*> Vertexs = gm->getVertexs();
	
	initVertexs(Vertexs);	

	(*root).setColor("gray");
	(*root).setDistance(0);
	(*root).setFather("NULL");	

	list<vertex_<string>*>* Q = new list<vertex_<string>*>();

	Q->push_back(root);

	while (!Q->empty()){

		vertex_<string>* vertexRemoved = Q->front();

		Q->pop_front();

		list<edge_<string>> edges = gm->getEdges((*vertexRemoved));
		
		markAdjacents(gm,edges,vertexRemoved,Q);	

		cout << root->getValue() << " " << vertexRemoved->getValue() << " " << vertexRemoved->getDistance() << endl;

		vertexRemoved->setColor("black");
	}
}
