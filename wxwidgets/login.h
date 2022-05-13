#pragma once
#include <wx/wx.h>

class Login : public wxDialog
{
public:
    Login(const wxString& title);

    wxTextCtrl* name;
    wxTextCtrl* passw;
    void OnLogin(wxCommandEvent& event);
    void OnBadInput(wxCommandEvent& event);
    void OnGoodInput(wxCommandEvent& event);
}; 
