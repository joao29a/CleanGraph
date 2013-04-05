#ifndef AMATRIX_H
#define AMATRIX_H
#include "DataStructure.h"
#include <unordered_map>  

using namespace std;

template <class Data>
class AdjacencyMatrix: public DataStructure<Data>{
private:
	typedef unordered_map<Data,int> Edge;
	typedef unordered_map<Data, Edge> Vertices;
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
	return  matrix[vertex][edge];
}

#endif


