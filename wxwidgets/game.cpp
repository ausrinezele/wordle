#include "game.h"


Game::Game(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(240, 390))
{
    //SetIcon(wxIcon(wxT("web.xpm")));
//----------menu items------------------------------------
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

//-----------------------grid---------------------------------
    wxColour black, green, yellow;
    black.Set(wxT("#333131"));
    green.Set(wxT("#43d12a"));
    yellow.Set(wxT("#e6d822"));

    sizer = new wxBoxSizer(wxVERTICAL);
    display = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1),
        wxSize(-1, -1), wxTE_RIGHT);
    sizer->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
    gs = new wxGridSizer(7, 5, 2,2);
//                      word 1
    wxPanel* letterbox11 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox11, 0, wxEXPAND);
    wxPanel* letterbox12 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox12, 0, wxEXPAND);
    wxPanel* letterbox13 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox13, 0, wxEXPAND);
    wxPanel* letterbox14 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox14, 0, wxEXPAND);
    wxPanel* letterbox15 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox15, 0, wxEXPAND); 
//                      word 2
    wxPanel* letterbox21 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox21, 0, wxEXPAND);
    wxPanel* letterbox22 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox22, 0, wxEXPAND);
    wxPanel* letterbox23 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox23, 0, wxEXPAND);
    wxPanel* letterbox24 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox24, 0, wxEXPAND);
    wxPanel* letterbox25 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox25, 0, wxEXPAND);
//                      word 3
    wxPanel* letterbox31 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox31, 0, wxEXPAND);
    wxPanel* letterbox32 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox32, 0, wxEXPAND);
    wxPanel* letterbox33 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox33, 0, wxEXPAND);
    wxPanel* letterbox34 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox34, 0, wxEXPAND);
    wxPanel* letterbox35 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox35, 0, wxEXPAND);

//                      word 4
    wxPanel* letterbox41 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox41, 0, wxEXPAND);
    wxPanel* letterbox42 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox42, 0, wxEXPAND);
    wxPanel* letterbox43 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox43, 0, wxEXPAND);
    wxPanel* letterbox44 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox44, 0, wxEXPAND);
    wxPanel* letterbox45 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox45, 0, wxEXPAND);
//                      word 5
    wxPanel* letterbox51 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox51, 0, wxEXPAND);
    wxPanel* letterbox52 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox52, 0, wxEXPAND);
    wxPanel* letterbox53 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox53, 0, wxEXPAND);
    wxPanel* letterbox54 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox54, 0, wxEXPAND);
    wxPanel* letterbox55 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox55, 0, wxEXPAND);
//                      word 6
    wxPanel* letterbox61 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox61, 0, wxEXPAND);
    wxPanel* letterbox62 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox62, 0, wxEXPAND);
    wxPanel* letterbox63 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox63, 0, wxEXPAND);
    wxPanel* letterbox64 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox64, 0, wxEXPAND);
    wxPanel* letterbox65 = new wxPanel(this, wxID_ANY);
    gs->Add(letterbox65, 0, wxEXPAND);
//                      guess button
    wxButton* buttonGuess = new wxButton(this, wxID_APPLY, wxT("Guess"));
    Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Game::OnGuess));
    buttonGuess->SetFocus();
    gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
    gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
   
    gs->Add(buttonGuess, 0, wxEXPAND);
    gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
    gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);

    sizer->Add(gs, 1, wxEXPAND);
    SetSizer(sizer);
    SetMinSize(wxSize(220, 390));
  
   
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
     std::string word = display->GetValue().ToStdString();//paima stringa (patikrinau veikia:DD)
}
