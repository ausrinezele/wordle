#pragma once
#include <wx/wx.h>
#include "user.h"
#include "DBH.h"

class Login : public wxDialog
{
public:
    Login(const wxString& title);


    void OnLogin(wxCommandEvent& event);

    bool isLogged();
    User* getloggedUser();
private:
    bool logged = false;
    User* user;
    wxTextCtrl* name;
    wxTextCtrl* passw;
    DBH database;
}; 
