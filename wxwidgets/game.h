#pragma once

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/event.h>
#include "rules.h"
#include "leaderboard.h"
#include "register.h"
#include "login.h"
#include "score.h"

class Game : public wxFrame
{
public:
    Game(const wxString& title);
//----------menu items--------------------
    void OnRules(wxCommandEvent& event);
    void OnLeaderboard(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnReg(wxCommandEvent& event);
    void OnLog(wxCommandEvent& event);
    void OnScore(wxCommandEvent& event);
    
    wxMenu* acc;
    wxMenuBar* menubar;
    wxMenu* file;
//----------------grid-----------------------    
    wxBoxSizer* sizer;
    wxGridSizer* gs;
    wxTextCtrl* display;
//------------guess button--------------------
    void OnGuess(wxCommandEvent& event);
//--------------------------------------------

};
