#pragma once
#include <wx/wx.h>

class Register : public wxDialog
{
public:
    Register(const wxString& title);

    wxTextCtrl* name;
    wxTextCtrl* email;
    wxTextCtrl* passw;
    void OnRegister(wxCommandEvent& event);
    void OnBadInput(wxCommandEvent& event);
    void OnGoodInput(wxCommandEvent& event);
};