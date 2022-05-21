#pragma once
#include <wx/wx.h>
#include "DBH.h"

class Register : public wxDialog
{
public:
    Register(const wxString& title);

    void OnRegister(wxCommandEvent& e);
    void OnBadInput(wxCommandEvent& event);
    void OnGoodInput(wxCommandEvent& event);
private:
    wxTextCtrl* name;
    wxTextCtrl* email;
    wxTextCtrl* passw;
    DBH dataBase;
};