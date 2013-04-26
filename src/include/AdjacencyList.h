#include "DataStructure.h"
#include <list>
#include <unordered_map>
using namespace std;

template < class Data > class AdjacencyList:public DataStructure < Data > {
  private:
    typedef list < edge_ < Data > >Edges;
    typedef vertex_ < Data > vertexAttributes;
    typedef unordered_map < Data, vertexAttributes > vertex_Map;
    typedef unordered_map < Data, Edges > vertex_Edges;
    vertex_Edges graph_edges;
    vertex_Map graph_vertexs;
  public:
    AdjacencyList() {
    };
    void addVertex(Data);
    void addEdge(Data, Data, int);
    void removeEdge(Data, Data);
    list < edge_ < Data >> getEdges(vertex_ < Data >);
    list < vertex_ < Data > *>getVertexs();
    vertex_ < Data > *getVertex(Data);
};

template < class Data >
    void AdjacencyList < Data >::addVertex(Data vertexA)
{
    graph_edges[vertexA];
    graph_vertexs[vertexA];
    graph_vertexs[vertexA].setValue(vertexA);
}

template < class Data >
    void AdjacencyList < Data >::addEdge(Data vertexA, Data vertexB,
					 int weight)
{
    edge_ < Data > edge(vertexB, weight);
    graph_edges[vertexA].push_back(edge);
}


template < class Data >
    void AdjacencyList < Data >::removeEdge(Data vertexA, Data vertexB)
{
    graph_edges[vertexA].remove(edge_ < Data > (vertexB, 0));
}

template < class Data >
    list < edge_ < Data >> AdjacencyList < Data >::getEdges(vertex_ <
							    Data > vertex)
{
    return (graph_edges[vertex.getValue()]);
}

template < class Data >
    list < vertex_ < Data > *>AdjacencyList < Data >::getVertexs()
{
    list < vertex_ < Data > *>keys;

  for (auto & kv:graph_vertexs) {
	const vertex_ < Data > *p = &(kv.second);
	vertex_ < Data > *v = const_cast < vertex_ < Data > *>(p);
	keys.push_front(v);
    }

    return keys;
}

template < class Data >
    vertex_ < Data > *AdjacencyList < Data >::getVertex(Data vertexA)
{
    return &(graph_vertexs[vertexA]);
}
