#ifndef BFS_H
#define BFS_H

#include "DataStructure.h"
#include "GraphManipulator.h"

class bfs {
  private:
    void initVertexs(list < vertex_ < string > *>);
    void markAdjacents(GraphManipulator *,
		       list < edge_ < string >>,
		       vertex_ < string > *,
		       list < vertex_ < string > *>*);
  public:
    void BFS(GraphManipulator *, vertex_ < string > *);
};

#endif
