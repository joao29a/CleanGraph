#include "DataStructure.h"
#include <list>
#include <map>
using namespace std;

template <class Data>
class AdjacencyList: public DataStructure<Data>{
private:
	//typedef map<Data, int> Edge;
	list<Data> Edges;
	typedef map<Data, Edges> List;
	List graph;
public:
	AdjacencyList(){};
	void addEdge(Data,Data);
	//void remove(Data,Data);
	//bool search(Data,Data);
};

template <class Data>
void AdjacencyList<Data>::addEdge(Data vertex, Data edge){	
	graph[vertex]=Edges.push_back(edge);
}
