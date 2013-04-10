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
	edge_(Data v, int w){ setVertex(v); setWeight(w);};
	Data getVertex() const { return vertex; };
	void setVertex(Data v){ vertex = v; };
	int getWeight(){ return weight; };
	void setWeight(int w){ weight = w; };
		
	bool operator==(const edge_<Data> &other) const{
		return (other.getVertex() == this->vertex);
	}
};

template<class Data>
class vertex_{
private:
	Data value;
public:
	vertex_(Data v){ setValue(v); };
	Data getValue(){ return value; };
	void setValue(Data v){ value = v; };
	// vertex == vertex
	bool operator==(const vertex_<Data> &other){
		return (other.getValue() == this->value);
	};
};

template<class Data>
class DataStructure{
public: 
	virtual void addVertex(Data) {};
	virtual void addEdge(Data,Data,int) {}; 
	virtual void removeEdge(Data,Data) {};
	virtual list<edge_<Data>> getEdges(Data){}; 
	virtual list<Data> getVertexs(){};
};

#endif
