#ifndef DFS_H
#define DFS_H

#include "GraphManipulator.h"
#include "DataStructure.h"

class dfs {
  protected:
    list < vertex_ < string > *>Vertexs;
    list < vertex_ < string > *>::iterator itVertexs;
    int time;
    virtual void setOutput_stamp(vertex_ < string > *);
    virtual void mainLoop(GraphManipulator *);
    void DFS_visit(GraphManipulator *, vertex_ < string > *);

  public:
    void DFS(GraphManipulator *);
};

#endif
