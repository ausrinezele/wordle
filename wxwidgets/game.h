#pragma once

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/event.h>
#include "rules.h"
#include "leaderboard.h"
#include "register.h"
#include "login.h"
#include "score.h"

#include <random>


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
    
private:
    wxMenu* acc;
    wxMenuBar* menubar;
    wxMenu* file;
    const int lettersInWord = 5;
    const int guessCount = 6;
    int guessNumber = 0;

    wxColour black, green, yellow, gray;


    static std::random_device rd;
    static std::mt19937 mt;


    std::string corrWord;
//----------------grid-----------------------    
    wxBoxSizer* sizer;
    wxGridSizer* gs;
    wxTextCtrl* display;
//------------guess button--------------------
    void OnGuess(wxCommandEvent& event);
//--------------------------------------------
    bool isWord(std::string guessedWord);
    void wordGen();
    bool letterInPos(int pos, char letter);
    bool letterExist(char letter);
};
