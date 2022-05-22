#pragma once
#include <wx/wx.h>
#include "DBH.h"
#include <string>

class Register : public wxDialog
{
public:
    Register(const wxString& title);

    void OnRegister(wxCommandEvent& e);
    void OnBadInput(wxCommandEvent& e);
    void OnGoodInput(wxCommandEvent& e);
private:
    wxTextCtrl* name;
    wxTextCtrl* email;
    wxTextCtrl* passw;
    DBH dataBase;

    bool uniqueName(std::string name);
    bool uniqueEmail(std::string email);
    bool corrEmail(std::string email);
};