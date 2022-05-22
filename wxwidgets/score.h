#pragma once
#include <wx/wx.h>

class Score : public wxDialog
{
private:
    wxStaticText* name;
    wxStaticText* score;

public:
    Score(const wxString& title);
    void setScore(int sc);
    void setName(std::string username);
};