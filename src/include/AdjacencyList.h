#include "DataStructure.h"
#include <list>
#include <map>
using namespace std;

template <class Data>
class AdjacencyList: public DataStructure<Data>{
private:
	struct edge_{
		Data edge;
		int weight;
	};

	typedef list<edge_> Edges;
	typedef map<Data,Edges> List;
	List graph;
public:
	AdjacencyList(){};
	void addEdge(Data,Data,int);
	//void remove(Data,Data);
	//bool search(Data,Data);
};

template <class Data>
void AdjacencyList<Data>::addEdge(Data vertex, Data edge, int weight){
	edge_ EDGE;
	EDGE.edge=edge;
	EDGE.weight=weight;
	graph[vertex].push_back(EDGE);
}

/*template <class Data>
void AdjacencyList<Data>::remove(Data vertex, Data edge){
	graph[vertex].remove
}

template <class Data>
void AdjacencyList<Data>::search(Data vertex, Data edge){
}*/
