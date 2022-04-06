#ifndef CHATGUI_H_
#define CHATGUI_H_
#include <wx/wx.h>
#include <memory>
class ChatLogic; 
class ChatBotPanelDialog : public wxScrolledWindow{
private:
     wxBoxSizer *_dialogSizer;
    wxBitmap _image;
    std::unique_ptr<ChatLogic> _chatLogic;
public:
ChatBotPanelDialog(wxWindow *parent, wxWindowID id);
    ~ChatBotPanelDialog();

 ChatLogic *GetChatLogicHandle() { return _chatLogic.get(); }

}
