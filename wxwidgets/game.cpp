#include "game.h"


Game::Game(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(220, 390))
{
    //SetIcon(wxIcon(wxT("web.xpm")));
//----------menu items---------------------------------
    menubar = new wxMenuBar;
    file = new wxMenu;

    file->Append(wxID_INFO, wxT("Rules"));
    file->Append(wxID_ABOUT, wxT("Leaderboard"));
    file->Append(wxID_EXIT, wxT("&Quit"));
    menubar->Append(file, wxT("&File"));
    SetMenuBar(menubar);

    Connect(wxID_INFO, wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(Game::OnRules));
    Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(Game::OnLeaderboard));
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(Game::OnQuit));

//--------------guess_button-------------------------------
    wxPanel* panel = new wxPanel(this, wxID_APPLY);

    wxButton* button = new wxButton(panel, wxID_APPLY, wxT("Guess"),
        wxPoint(65, 300));
    Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Game::OnGuess));
    button->SetFocus();

//-----------------panels----------------------------------
    



//---------------------------------------------------------
    Centre();

}
//----------menu items--------------------------------- galimai reikės dar kažką pridėti
void Game::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}
void Game::OnLeaderboard(wxCommandEvent& WXUNUSED(event))
{
    Leaderboard* sl = new Leaderboard(wxT("The Leaderboard"));
    sl->ShowModal();
    sl->Destroy();
}
void Game::OnRules(wxCommandEvent& WXUNUSED(event))
{
    Rules* sp = new Rules(wxT("The Game rules"));
    sp->ShowModal();
    sp->Destroy();
}
//--------------guess_button------------------------------- reik keist obvs
void Game::OnGuess(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}