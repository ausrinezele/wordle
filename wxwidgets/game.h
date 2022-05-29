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
//#include "word.h"


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
    void OnInternal(wxCommandEvent& event);
    void OnExternal(wxCommandEvent& event);

    void addWordsToDB(std::string file_name);
    
private:

    DBH dataBase;
    User* player = nullptr;
    //Word word;

    wxMenu* acc;
    wxMenuBar* menubar;
    wxMenu* file;
    wxMenu* source;
    const int lettersInWord = 5;
    const int guessCount = 6;
    int guessNumber = 0;

    wxColour black, green, yellow, gray;


    static std::random_device rd;
    static std::mt19937 mt;

    int score = 0;
    int totalScore = 0;
    int maxScore = 30;

    std::vector<std::string> wordList;
    std::string corrWord;
//----------------grid-----------------------    
    wxBoxSizer* sizer;
    wxGridSizer* grid;
    wxTextCtrl* inputBox;
    wxStaticText** boxes;
//------------guess button--------------------
    wxButton* restart;

    void OnGuess(wxCommandEvent& e);
    void OnLogOut(wxCommandEvent& e);
    void OnRestart(wxCommandEvent& e);

//--------------------------------------------
    bool isWord(std::string guessedWord);
    void wordGen();
    bool letterInPos(int pos, char letter);
    bool letterExist(char letter);

    void readWordsFromFile(std::string fname);

    void getWordsFromDB();



    void addLetterBoxes();

    void ltrim(std::string& s);
    void rtrim(std::string& s);
    void trim(std::string& s);
};
