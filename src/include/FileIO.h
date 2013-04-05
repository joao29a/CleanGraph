#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "GraphManipulator.h"

using namespace std;
class FileIO{
private:
	vector<string> vertex;
	vector<string> edges;
	void get_file_contents(const char*);
	void processVetex(GraphManipulator*);	
	void processEdges(GraphManipulator*);
public:
	FileIO(const char* fileName){
		get_file_contents(fileName);
	}
	
	void fillStructureWithDataInFile(GraphManipulator*);
};

#endif

