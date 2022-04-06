#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include <vector>
#include <string>
class GraphNode;
class GraphEdge{
private:
    GraphNode *_childNode;
    GraphNode *_parentNode;
};