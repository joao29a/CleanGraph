#ifndef SCC_H
#define SCC_H

#include "GraphManipulator.h"
#include "dfs.h"


bool sortOutput(const vertex_ < string > &otherA,
		const vertex_ < string > &otherB);

class scc:public dfs {
  protected:
    list < vertex_ < string >> queue;
    list < vertex_ < string >> vertexOrd;
    list < vertex_ < string >>::iterator itOrdVertex;
    void outputTree(GraphManipulator *);
    void mainLoop(GraphManipulator *);
    void transposed(GraphManipulator *, GraphManipulator *);
    void setOutput_stamp(vertex_ < string > *);

  public:
    void stronglyComponent(GraphManipulator *);
};

#endif
