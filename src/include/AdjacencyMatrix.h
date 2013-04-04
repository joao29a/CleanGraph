#include "DataStructure.h"
#include <map>  

using namespace std;

template <class Data>
class AdjacencyMatrix: public DataStructure<Data>{
private:
	typedef map<Data,int> Edge;
	typedef map<Data, Edge> Vertices;
	Vertices matrix;  
public: 
	AdjacencyMatrix(){};
	void addEdge(Data,Data); 
	void remove(Data,Data); 
	bool search(Data,Data); 
};

template <class Data>
void AdjacencyMatrix<Data>::addEdge(Data vertex, Data edge){
	matrix[vertex][edge] = 1;
}

template <class Data>
void AdjacencyMatrix<Data>::remove(Data vertex, Data edge){
	matrix[vertex][edge] = 0;
}

template <class Data>
bool AdjacencyMatrix<Data>::search(Data vertex,Data edge){
	return (bool) matrix[vertex][edge];
}
