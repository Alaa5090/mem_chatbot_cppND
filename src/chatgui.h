#ifndef CHATGUI_H_
#define CHATGUI_H_
#include <wx/wx.h>
#include <memory>
class ChatLogic; 
class ChatBotPanelDialog : public wxScrolledWindow{

     wxBoxSizer *_dialogSizer;
    wxBitmap _image;
    std::unique_ptr<ChatLogic> _chatLogic;
}
