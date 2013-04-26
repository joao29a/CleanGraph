#include "include/ts.h"
#include <iostream>

list < vertex_ < string >> ts::topologicalSort(GraphManipulator * gm)
{
    ts obj;
    obj.DFS(gm);
    return obj.listVertex;
}

void ts::setOutput_stamp(vertex_ < string > *u)
{
    u->setOutput(time);
    listVertex.push_front(*u);
}
