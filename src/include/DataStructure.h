#ifndef DS_H
#define DS_H
#include <list>

using namespace std;

template<class Data>
class edge_{
private:
	Data vertex;
	int weight;
public:
	edge_(Data v, int w){ vertex = v; weight = w;};
	Data getVertex() const { return vertex; };
	void setVertex(Data v){ vertex = v; };
	int getWeight(){ return weight; };
	void setWeight(int w){ weight = w; };
		
	bool operator==(const edge_<Data> &other) const{
		return (other.getVertex() == this->vertex);
	}
};


template<class Data>
class DataStructure{
public: 
	virtual void addEdge(Data,Data,int) {}; 
	virtual void removeEdge(Data,Data) {};
	virtual list<edge_<Data>> getEdges(Data){}; 
	virtual list<Data> getVertexs(){};
};

#endif
