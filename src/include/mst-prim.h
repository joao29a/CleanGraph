#ifndef MSTPRIM_H
#define MSTPRIM_H

#include "HeapTree.h"
#include "GraphManipulator.h"
#include "DataStructure.h"

class prim {
  private:
    void initVertexs(list < vertex_ < string > *>);
    void fillHeapTree(list < vertex_ < string > *>, HeapTree < string > *);
  public:
    void mstPrim(GraphManipulator *, vertex_ < string > *);
    void printMST(GraphManipulator *);
};

#endif
