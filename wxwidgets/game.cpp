#include "game.h"

const int lettersInWord = 5;
const int guessCount = 6;
int guessNumber = 1;

Game::Game(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(240, 390))
{
    //SetIcon(wxIcon(wxT("web.xpm")));
//----------menu items------------------------------------
    wxMenuBar *menubar = new wxMenuBar;
    wxMenu* file = new wxMenu;
    wxMenu* acc = new wxMenu;
    
    acc->Append(wxID_FIRST, wxT("Register"));
    acc->Append(wxID_LAST, wxT("Login"));
    acc->Append(wxID_FLOPPY, wxT("Check score"));
    file->AppendSubMenu(acc, wxT("Account"));
        
    file->Append(wxID_INFO, wxT("Rules"));
    file->Append(wxID_ABOUT, wxT("Leaderboard"));
    file->Append(wxID_EXIT, wxT("&Quit"));
    menubar->Append(file, wxT("&File"));
    SetMenuBar(menubar);

    Connect(wxID_INFO, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Game::OnRules));
    Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Game::OnLeaderboard));
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Game::OnQuit));
    Connect(wxID_FIRST, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Game::OnReg));
    Connect(wxID_LAST, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Game::OnLog));
    Connect(wxID_FLOPPY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Game::OnScore));

//-----------------------grid---------------------------------
    wxColour black, green, yellow;
    black.Set(wxT("#333131"));
    green.Set(wxT("#43d12a"));
    yellow.Set(wxT("#e6d822"));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxTextCtrl* display = new wxTextCtrl(this, 999, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_RIGHT);
    sizer->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
    wxGridSizer* gs = new wxGridSizer(guessCount+1, lettersInWord, 2,2);
////                      word 1
    for (int i = 0; i < guessCount * lettersInWord; i++) {
    gs->Add(new wxStaticText(this,i,"a",wxPoint(0,0),wxSize(0,0), wxALIGN_CENTRE_HORIZONTAL), 0, wxEXPAND); // bus reikalingi man atrodo id tai del to priskiriu su i, nes man atrodo pagal juos galesi deliot ir nereiks kiekvienam skirtingo letterbox
    wxWindow* window = FindWindowById(i);
    window->SetBackgroundColour(green);
    window->Refresh();
    }
    int guessNumber = 1;
    std::string name = "ABCDE";
    
    for (int i = 0 * guessNumber; i < lettersInWord * guessNumber; i++)
        FindWindowById(i, this)->SetLabel(name[i]);
//                          guess button
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
void Game::OnReg(wxCommandEvent& WXUNUSED(event))
{
    Register* sr = new Register(wxT("Register"));
    sr->ShowModal();
    sr->Destroy();
}
void Game::OnLog(wxCommandEvent& WXUNUSED(event))
{
    Login* sr = new Login(wxT("Login"));
    sr->ShowModal();
    sr->Destroy();
}
void Game::OnScore(wxCommandEvent& WXUNUSED(event))
{
    Score* sr = new Score(wxT("Score"));
    sr->ShowModal();
    sr->Destroy();
}
//--------------guess_button------------------------------- reik keist obvs
void Game::OnGuess(wxCommandEvent& e)
{
   wxWindow* window = FindWindowById(e.GetId());            //cia pasirodo gauni mygtuko id o ne display lauko, reik kazkaip papassint dar viena parametra i funcija
   wxTextCtrl* word = wxDynamicCast(window, wxTextCtrl);
   if (!word) {
       wxMessageBox(std::to_string(e.GetId()));
       wxMessageBox("word is null");
       return;
   }
   std::string strWord = word->GetValue().ToStdString();
   for (int i = 0 * guessNumber; i < lettersInWord * guessNumber; i++) {
       FindWindowById(i)->SetLabel(strWord[i]);
    }
    guessNumber++;

     //std::string word = display->GetValue().ToStdString();//paima stringa (patikrinau veikia:DD)
}
