#ifndef CHATBOT_H_
#define CHATBOT_H_
#include <wx/bitmap.h>
#include <string>
class GraphNode;
class ChatLogic;
class ChatBot{
    private:
     wxBitmap *_image;
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

}
