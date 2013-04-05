#include "include/AdjacencyMatrix.h"
#include "include/GraphManipulator.h"
#include <iostream>
#include "include/FileIO.h"
#include <string>

int main(void){
	AdjacencyMatrix<string>* matrix = new AdjacencyMatrix<string>();
	GraphManipulator *gm = new GraphManipulator(matrix);
	FileIO io("graphs/ex1");
	io.fillStructureWithDataInFile(gm);

	return 0;
}
