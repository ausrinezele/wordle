#include "login.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Login::Login(const wxString& title) : wxDialog(NULL, wxID_ANY, title,
    wxDefaultPosition, wxSize(240, 200))
{

    wxStaticText* nickname = new wxStaticText(this, wxID_ANY, wxT("Nickname:"),
        wxPoint(15, 15));
    wxPanel* npanel = new wxPanel(this, wxID_ANY, wxPoint(25, 35), wxSize(100, 20));
    name = new wxTextCtrl(npanel, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT);

    wxStaticText* emailAddress = new wxStaticText(this, wxID_ANY, wxT("Password:"),
        wxPoint(15, 55));
    wxPanel* ppanel = new wxPanel(this, wxID_ANY, wxPoint(25, 75), wxSize(100, 20));
    passw = new wxTextCtrl(ppanel, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT);

    wxButton* loginButton = new wxButton(this, wxID_NO, wxT("Login"),
        wxPoint(70, 120));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Login::OnLogin));
    loginButton->SetFocus();
    Centre();

    this->Centre();
}
void Login::OnLogin(wxCommandEvent& WXUNUSED(event))
{
    std::string username = name->GetValue().ToStdString();
    std::string userpassw = passw->GetValue().ToStdString();
}
void Login::OnBadInput(wxCommandEvent& WXUNUSED(event))
{
    wxMessageDialog* error = new wxMessageDialog(NULL,
        wxT("Incorrect name or password"), wxT("Error"), wxOK | wxICON_ERROR);
    error->ShowModal();
}
void Login::OnGoodInput(wxCommandEvent& WXUNUSED(event))
{
    wxMessageDialog* okay = new wxMessageDialog(NULL,
        wxT("Welcome back!"), wxT("Success"), wxOK);
    okay->ShowModal();
}
