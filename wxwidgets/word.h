#pragma once
#include <wx/wx.h>
#include "DBH.h"
#include <string>
class Word : public wxDialog
{
public:
    Word(const wxString& title);
private:
    wxTextCtrl* word;


    DBH dataBase;
    void addWordToDb();
    void ltrim(std::string& s);
    void rtrim(std::string& s);
    void trim(std::string& s);
};