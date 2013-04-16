#include "DataStructure.h"
#include <list>
#include <unordered_map>
using namespace std;

template <class Data>
class AdjacencyList: public DataStructure<Data>{
private:
	typedef list<edge_<Data> > Edges;
	typedef unordered_map<vertex_<Data>,Edges,vertex_hash<Data>> List;
	List graph;
public:
	AdjacencyList(){};
	void addVertex(Data);
	void addEdge(Data,Data,int);
	void removeEdge(Data,Data);
	list<edge_<Data>> getEdges(vertex_<Data>);
	list<vertex_<Data>*> getVertexs();
	void setColor(vertex_<Data>,Data);
};

template <class Data>
void AdjacencyList<Data>::addVertex(Data vertexA){
	graph[vertex_<Data>(vertexA)];
}

template <class Data>
void AdjacencyList<Data>::addEdge(Data vertexA, Data vertexB, int weight){
	edge_<Data> edge(vertexB,weight);
	graph[vertex_<Data>(vertexA)].push_back(edge);
}


template <class Data>
void AdjacencyList<Data>::removeEdge(Data vertexA, Data vertexB){
	graph[vertexA].remove(edge_ <Data>(vertexB,0));
}

template <class Data>
list<edge_<Data>> AdjacencyList<Data>::getEdges(vertex_<Data> vertex){
	return (graph[vertex]);
}

template <class Data>
list<vertex_<Data>*> AdjacencyList<Data>::getVertexs(){
	        list<vertex_<Data>*> keys;

                for(auto kv : graph) {
			// * = const *
			vertex_<Data>* v = &(kv.first);  
                        keys.push_front(v);
                }
                return keys;
}

template <class Data>
void AdjacencyList<Data>::setColor(vertex_<Data> vertex, Data color){
	//graph[vertex.setColor(color)];
}
