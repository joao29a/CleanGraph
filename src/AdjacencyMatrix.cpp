#include "include/AdjacencyMatrix.h"
#include <iostream>

int main(void){
	AdjacencyMatrix<int> am;
	int  i = 1;
	int b = 2;
	am.addEdge(1,2);
	cout << am.search(1,2);
	return 0;
}
