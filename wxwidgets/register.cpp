#include "register.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Register::Register(const wxString& title) : wxDialog(NULL, wxID_ANY, title,
    wxDefaultPosition, wxSize(240, 220))
{

    wxStaticText* nickname = new wxStaticText(this, wxID_ANY, wxT("Nickname:"), wxPoint(15, 15));
    wxPanel* npanel = new wxPanel(this, wxID_ANY, wxPoint(25, 35), wxSize(100, 20));
    name = new wxTextCtrl(npanel, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT);

    wxStaticText* emailAddress = new wxStaticText(this, wxID_ANY, wxT("Email address:"),wxPoint(15, 55));
    wxPanel* epanel = new wxPanel(this, wxID_ANY, wxPoint(25, 75), wxSize(180, 20));
    email = new wxTextCtrl(epanel, -1, wxT(""), wxPoint(-1, -1), wxSize(180, -1), wxTE_LEFT);

    wxStaticText* password = new wxStaticText(this, wxID_ANY, wxT("Password:"),wxPoint(15, 95));
    wxPanel* ppanel = new wxPanel(this, wxID_ANY, wxPoint(25, 115), wxSize(100, 20));
    passw = new wxTextCtrl(ppanel, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT);

    wxButton* registerButton = new wxButton(this, wxID_EXIT, wxT("Register"),wxPoint(70, 150));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Register::OnRegister));
    registerButton->SetFocus();
    Centre();

    this->Centre();
}
void Register::OnRegister(wxCommandEvent& e)
{
    wxMessageBox("register clicked");
    std::string username = name->GetValue().ToStdString();
    std::string useremail = email->GetValue().ToStdString();
    std::string userpassw = passw->GetValue().ToStdString();
    if (!uniqueName(username) || !uniqueEmail(useremail)) return;
    dataBase.addUser(username, useremail, userpassw);
    e.Skip();
}
void Register::OnBadInput(wxCommandEvent& e)
{
    wxMessageDialog* error = new wxMessageDialog(NULL, wxT("Name or e-mail is already in use"), wxT("Error"), wxOK | wxICON_ERROR);
    error->ShowModal();
    e.Skip();
}
void Register::OnGoodInput(wxCommandEvent& e)
{
    wxMessageDialog* okay = new wxMessageDialog(NULL, wxT("Welcome"), wxT("Success"), wxOK);
    okay->ShowModal();
    e.Skip();
}
bool Register::uniqueName(std::string name) {
    for(auto &el: dataBase.getAllNames())
        if (el == name) {
            wxMessageBox("Name already exits");
            return false;
        }
    return true;
}
bool Register::uniqueEmail(std::string email) {
    for (auto& el : dataBase.getAllNames())
        if (el == email) {
            wxMessageBox("Email already exits");
            return false;
        }
    return true;
}

