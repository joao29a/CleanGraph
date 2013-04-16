#include "DataStructure.h"
#include "GraphManipulator.h"
#include <list>

template <class Data>
class bfs: public vertex_<Data>{
private:
	string color;
	int distance;
	vertex_<Data> father;
public:
	void BFS(GraphManipulator*);
	void setColor(string color) { this.color = color; };
	void setDistance(int distance) { this.distance = distance; };
	void setFather(vertex_<Data> son) { father = son; };
	string getColor() { return color; };
	int getDistance() { return distance; };
};

template<class Data>
void bfs<Data>::BFS(GraphManipulator *gm){
	list<vertex_<string>*> Vertex = gm->getVertexs();
	list<vertex_<string>*>::iterator itVertex;
	for (itVertex = Vertex.begin(); itVertex != Vertex.end(); itVertex++){
		(*itVertex)->setColor("white");
		cout << "Vertex " << (*itVertex)->getColor() << endl;
	//	gm->setColor(*itVertex,"white");
	//	(*itVertex).setDistance(0);
	}
	Vertex = gm->getVertexs();
	//list<vertex_*<string>>::iterator itVertex;
	for (itVertex = Vertex.begin(); itVertex != Vertex.end(); itVertex++){
		cout << "Vertex " << (*itVertex)->getColor() << endl;
	}
	/*for (itVertex = Vertex.begin(); itVertex != Vertex.end(); itVertex++){
		cout << "Vertex " << itVertex.getValue() << endl;
		cout << " cor: " << itVertex.getColor() << endl;
		cout << " distancia: " << itVertex.getDistance() << endl;
	}
	itVertex = Vertex.begin();
	(*itVertex)->setColor("gray");
	(*itVertex)->setDistance(0);
	list<bfs<string>> Q;
	Q.push_back(itVertex.first);
	while (!Q.empty()){	
	*/
}
