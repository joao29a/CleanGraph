#include "DataStructure.h"
#include "GraphManipulator.h"

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
