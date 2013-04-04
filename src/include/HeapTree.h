#ifndef HEAPTREE_H
#define HEAPTREE_H

#include "DataStructure.h"
#include <queue>
#include <iostream>

using namespace std;

template <class Data>
class HeapTree: public DataStructure<Data>{
private:
	std::priority_queue<Data> priorityQueue;
public:
	HeapTree(){}; 
	void add(Data);
	Data remove(Data);
	Data search(Data); 
};

template <class Data>
void HeapTree<Data>::add(Data data){
	priorityQueue.push(data);
}

template <class Data>
Data HeapTree<Data>::remove(Data data){
        Data res = priorityQueue.top();
        priorityQueue.pop();
        return res;
}
        
template <class Data>
Data HeapTree<Data>::search(Data data){
	return priorityQueue.top();
}

#endif
