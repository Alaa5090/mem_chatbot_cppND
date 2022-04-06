#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"
class GraphEdge;
class GraphNode{
private:

     std::vector<std::unique_ptr<GraphEdge>> _childEdges;

}