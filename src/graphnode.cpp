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
