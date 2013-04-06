#include "include/FileIO.h"
#include <cstdio>

using namespace std;

void FileIO::get_file_contents(const char *filename)
{
  string line;
  ifstream infile(filename,ios_base::in);
  bool isVertex = true;

  while (getline(infile, line, '\n')){
	if(line == "#"){
		isVertex = false;	
	}else{
		if(isVertex){
			vertex.push_back (line);
		}else{
			edges.push_back (line);
		}
	}
  }

}


void FileIO::processVetex(GraphManipulator* g){
	for (vector<string>::iterator it = vertex.begin(); it!=vertex.end(); ++it) {
    		g->addVertex(*it);
	}
}

void FileIO::processEdges(GraphManipulator* g){
	char a[80];
	char b[80];
	char c[80];
	for (vector<string>::iterator it = edges.begin(); it!=edges.end(); ++it) {
		sscanf((*it).c_str(),"%s %s %s",a,b,c);
		g->addEdge(a,b,atoi(c));
	}
}

void FileIO::fillStructureWithDataInFile(GraphManipulator* g){
	processVetex(g);
	processEdges(g);
}

