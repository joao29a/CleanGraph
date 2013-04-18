#ifndef HEAPTREE_H
#define HEAPTREE_H

#include "DataStructure.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <class Data>
class HeapTree: public DataStructure<Data>{
private:
	vector<vertex_<Data>> vectorVertex;
public:
	HeapTree(){}; 
	void add(vertex_<Data>);
	vertex_<Data> extractMin();
	void heapMin();
	bool search(vertex_<Data>);
	bool empty();
	void refreshHeap(vertex_<Data>);
	void print();
};

template <class Data>
void HeapTree<Data>::add(vertex_<Data> vertexA){
	vectorVertex.push_back(vertexA);
}

template <class Data>
vertex_<Data> HeapTree<Data>::extractMin(){
        vertex_<Data> res = vectorVertex.front();
        pop_heap(vectorVertex.begin(),vectorVertex.end());
	vectorVertex.pop_back();
        return res;
}

template <class Data>
void HeapTree<Data>::heapMin(){
	make_heap(vectorVertex.begin(),vectorVertex.end());
}
        
template <class Data>
bool HeapTree<Data>::search(vertex_<Data> vertexA){
	return find(vectorVertex.begin(),vectorVertex.end(),vertexA)
			!= vectorVertex.end();
}

template <class Data>
bool HeapTree<Data>::empty(){
	return vectorVertex.empty();
}

template <class Data>
void HeapTree<Data>::refreshHeap(vertex_<Data> vertexA){	
	replace(vectorVertex.begin(),vectorVertex.end(),vertexA,vertexA);
}

template <class Data>
void HeapTree<Data>::print(){
	typename vector<vertex_<Data>>::iterator it;
	for (it=vectorVertex.begin();it!=vectorVertex.end();it++){
		cout << (*it).getValue() << " " << (*it).getKey() << endl;
	}
	cout << endl;
}

#endif
