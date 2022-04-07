#include "graphnode.h"
#include "graphedge.h"
GraphEdge::GraphEdge(int id)
{
    _id = id;
}
void GraphEdge::SetChildNode(GraphNode *childNode)
{
    _childNode = childNode;
}
