#include "login.h"
#include <wx/stattext.h>

Login::Login(const wxString& title) : wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(240, 200))
{
    wxStaticText* nickname = new wxStaticText(this, wxID_ANY, wxT("Nickname:"), wxPoint(15, 15));
    wxPanel* npanel = new wxPanel(this, wxID_ANY, wxPoint(25, 35), wxSize(100, 20));
    name = new wxTextCtrl(npanel, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT);

    wxStaticText* emailAddress = new wxStaticText(this, wxID_ANY, wxT("Password:"), wxPoint(15, 55));
    wxPanel* ppanel = new wxPanel(this, wxID_ANY, wxPoint(25, 75), wxSize(100, 20));
    passw = new wxTextCtrl(ppanel, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT);

    wxButton* loginButton = new wxButton(this, wxID_EXIT, wxT("Login"), wxPoint(70, 120));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Login::OnLogin));
    Centre();

    this->Centre();
}
void Login::OnLogin(wxCommandEvent& WXUNUSED(event))
{
    std::string username = name->GetValue().ToStdString();
    std::string userpassw = passw->GetValue().ToStdString();
    user = database.findUser(username, userpassw);
    if (!user) {
        wxMessageBox("User does not exist");
        return;
    }
    logged = true;
    wxMessageBox("user set");
}
bool Login::isLogged() {
    return logged;
}
User* Login::getloggedUser() {
    return user;
}

