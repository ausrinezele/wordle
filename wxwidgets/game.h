#pragma once

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/event.h>
#include "rules.h"
#include "leaderboard.h"
#include "register.h"
#include "login.h"
#include "score.h"
#include <fstream>
#include <vector>

#include <random>
#include "DBH.h"
#include "user.h"


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

    DBH dataBase;
    User* player = nullptr;

    wxMenu* acc;
    wxMenuBar* menubar;
    wxMenu* file;
    const int lettersInWord = 5;
    const int guessCount = 6;
    int guessNumber = 0;

    wxColour black, green, yellow, gray;


    static std::random_device rd;
    static std::mt19937 mt;

    int score = 0;
    int maxScore = 30;

    std::vector<std::string> wordList;
    std::string corrWord;
//----------------grid-----------------------    
    wxBoxSizer* sizer;
    wxGridSizer* grid;
    wxTextCtrl* inputBox;
    wxStaticText** boxes;
//------------guess button--------------------
    void OnGuess(wxCommandEvent& e);
    void OnLogOut(wxCommandEvent& e);

//--------------------------------------------
    bool isWord(std::string guessedWord);
    void wordGen(std::string fvardas);
    bool letterInPos(int pos, char letter);
    bool letterExist(char letter);
};
