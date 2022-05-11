#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/event.h>
#include "panels.h"
#include "rules.h"
#include "leaderboard.h"

class Game : public wxFrame
{
public:
    Game(const wxString& title);
//----------menu items--------------------
    void OnRules(wxCommandEvent& event);
    void OnLeaderboard(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);

    wxMenuBar* menubar;
    wxMenu* file;
//------------guess button--------------------
    void OnGuess(wxCommandEvent& event);
//--------------------------------------------

};