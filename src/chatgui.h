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

    void paintEvent(wxPaintEvent &evt);
    void paintNow();
    void render(wxDC &dc);
    void AddDialogItem(wxString text, bool isFromUser = true);
    void PrintChatbotResponse(std::string response);

    DECLARE_EVENT_TABLE()
};
class ChatBotPanelDialogItem : public wxPanel{
    
}

 



