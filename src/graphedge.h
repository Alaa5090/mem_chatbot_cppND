#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include <vector>
#include <string>
class GraphNode;
class GraphEdge{
private:
    GraphNode *_childNode;
    GraphNode *_parentNode;
    int _id;
    std::vector<std::string> _keywords; // list of topics associated with this edge
public:
    GraphEdge(int id);
};