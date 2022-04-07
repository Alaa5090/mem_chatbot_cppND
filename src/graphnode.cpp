#include "graphedge.h"
#include "graphnode.h"
GraphNode::GraphNode(int id)
{
    _id = id;
}
GraphNode::~GraphNode(){
delete _chatBot; 
}
void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}
void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}