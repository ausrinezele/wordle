#pragma once

#include <wx/wx.h>
#include <vector>
#include "user.h"
#include "DBH.h"

class Leaderboard : public wxDialog
{
private:
    std::vector<User> leaders;
    DBH database;

public:
    Leaderboard(const wxString& title);

};