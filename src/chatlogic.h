#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include "chatgui.h"
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
    private:
     std::vector<std::unique_ptr<GraphNode>> _nodes;
GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;
 typedef std::vector<std::pair<std::string, std::string>> tokenlist;




}