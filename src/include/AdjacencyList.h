#include "DataStructure.h"
#include <list>
#include <unordered_map>
using namespace std;

template <class Data>
class AdjacencyList: public DataStructure<Data>{
private:
	typedef list<edge_<Data>> Edges;
	typedef unordered_map<Data,Edges> List;
	List graph;
public:
	AdjacencyList(){};
	void addEdge(Data,Data,int);
	void removeEdge(Data,Data);
	list<edge_<Data>> getEdges(Data);
	list<Data> getVertexs();
};

template <class Data>
void AdjacencyList<Data>::addEdge(Data vertexA, Data vertexB, int weight){
	edge_<Data> edge(vertexB,weight);
	graph[vertexA].push_back(edge);
}


template <class Data>
void AdjacencyList<Data>::removeEdge(Data vertexA, Data vertexB){
	graph[vertexA].remove(edge_ <Data>(vertexB,0));
}

template <class Data>
list<edge_<Data>> AdjacencyList<Data>::getEdges(Data vertex){
	return (graph[vertex]);
}

template <class Data>
list<Data> AdjacencyList<Data>::getVertexs(){
	        list<Data> keys;

                for(auto kv : graph) {
                        keys.push_back(kv.first);
                }
                return keys;
}
