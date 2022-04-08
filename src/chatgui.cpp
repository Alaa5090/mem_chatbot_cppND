#include <wx/filename.h>
#include <wx/colour.h>
#include <wx/image.h>
#include <string>
#include "chatgui.h"
#include "chatbot.h"
#include "chatlogic.h"

const int width = 414;
const int height = 736;

IMPLEMENT_APP(ChatBotApp);

std::string dataPath = "../";
std::string imgBasePath = dataPath + "images/";

bool ChatBotApp::OnInit()
{
    
    ChatBotFrame *chatBotFrame = new ChatBotFrame(wxT("Udacity ChatBot"));
    chatBotFrame->Show(true);

    return true;
}

ChatBotFrame::ChatBotFrame(const wxString &title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height))
{
    ChatBotFrameImagePanel *ctrlPanel = new ChatBotFrameImagePanel(this);
   
   _panelDialog = new ChatBotPanelDialog(ctrlPanel, wxID_ANY);
    
    int idTextXtrl = 1;
    _userTextCtrl = new wxTextCtrl(ctrlPanel, idTextXtrl, "", wxDefaultPosition, wxSize(width, 50), wxTE_PROCESS_ENTER, wxDefaultValidator, wxTextCtrlNameStr);
    Connect(idTextXtrl, wxEVT_TEXT_ENTER, wxCommandEventHandler(ChatBotFrame::OnEnter));
     
     wxBoxSizer *vertBoxSizer = new wxBoxSizer(wxVERTICAL);
    vertBoxSizer->AddSpacer(90);
    vertBoxSizer->Add(_panelDialog, 6, wxEXPAND | wxALL, 0);
    vertBoxSizer->Add(_userTextCtrl, 1, wxEXPAND | wxALL, 5);
    ctrlPanel->SetSizer(vertBoxSizer);

     this->Centre();
}
void ChatBotFrame::OnEnter(wxCommandEvent &WXUNUSED(event)){

wxString userText = _userTextCtrl->GetLineText(0);

 _panelDialog->AddDialogItem(userText, true);

   _userTextCtrl->Clear();

   _panelDialog->GetChatLogicHandle()->SendMessageToChatbot(std::string(userText.mb_str()));
}
BEGIN_EVENT_TABLE(ChatBotFrameImagePanel, wxPanel)
EVT_PAINT(ChatBotFrameImagePanel::paintEvent) // catch paint events
END_EVENT_TABLE()

ChatBotFrameImagePanel::ChatBotFrameImagePanel(wxFrame *parent) : wxPanel(parent){
}

void ChatBotFrameImagePanel::paintEvent(wxPaintEvent &evt)
{
    wxPaintDC dc(this);
    render(dc);
}
void ChatBotFrameImagePanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}
void ChatBotFrameImagePanel::render(wxDC &dc){
wxString imgFile = imgBasePath + "sf_bridge.jpg";
    wxImage image;
    image.LoadFile(imgFile);

    wxSize sz = this->GetSize();
    wxImage imgSmall = image.Rescale(sz.GetWidth(), sz.GetHeight(), wxIMAGE_QUALITY_HIGH);
    _image = wxBitmap(imgSmall);
    
    dc.DrawBitmap(_image, 0, 0, false);

}
 BEGIN_EVENT_TABLE(ChatBotPanelDialog, wxPanel)
EVT_PAINT(ChatBotPanelDialog::paintEvent) 
END_EVENT_TABLE()
 ChatBotPanelDialog::ChatBotPanelDialog(wxWindow *parent, wxWindowID id)
    : wxScrolledWindow(parent, id)
{
 _dialogSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(_dialogSizer);

 wxInitAllImageHandlers();

