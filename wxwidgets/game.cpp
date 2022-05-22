#include "game.h"

std::random_device Game::rd;

std::mt19937 Game::mt(Game::rd());

static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}
Game::Game(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(240, 390))
{
    wordGen("zodziai.txt"); //sugeneruoja zodi
    wxMessageBox(corrWord); //SPAUSDINA TEISINGA ZODI
    //SetIcon(wxIcon(wxT("web.xpm")));
    //----------menu items------------------------------------
    menubar = new wxMenuBar;
    file = new wxMenu;
    acc = new wxMenu;
    
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
    black.Set(wxT("#333131"));
    green.Set(wxT("#008800"));
    yellow.Set(wxT("#e6d822"));
    gray.Set(wxT("#DAD8CB"));


    sizer = new wxBoxSizer(wxVERTICAL);
    inputBox = new wxTextCtrl(this, 999, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT);
    sizer->Add(inputBox, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
    grid = new wxGridSizer(guessCount+1, lettersInWord, 2,2);
////                      word 1

    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false); // font parameters
    boxes = new wxStaticText *[lettersInWord * guessCount];
    for (int i = 0; i < guessCount * lettersInWord; i++) {
        boxes[i] = new wxStaticText(this, i, "", wxPoint(0, 0), wxSize(0, 0), wxALIGN_CENTRE_HORIZONTAL);
        grid->Add(boxes[i], 0, wxEXPAND);
        boxes[i]->SetBackgroundColour(gray);
        boxes[i]->SetFont(font); // setting font
    }
//                          guess button
    wxButton* buttonGuess = new wxButton(this, wxID_APPLY, wxT("Guess"));
    Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Game::OnGuess));

    grid->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
    grid->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
    grid->Add(buttonGuess, 0, wxEXPAND);
    grid->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
    grid->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);

    sizer->Add(grid, 1, wxEXPAND);
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
    if (!player) {
        sr->ShowModal();
        player = sr->getloggedUser();
    }
    else wxMessageBox("User " + player->getNick() + " is logged in");
    sr->Destroy();
}
void Game::OnScore(wxCommandEvent& WXUNUSED(event))
{
    if (player) {
        Score* sr = new Score(wxT("Score"));
        sr->setScore(player->getScore());
        sr->setName(player->getNick());
        sr->ShowModal();
        sr->Destroy();
    }
    else wxMessageBox("You must log in first");
}
//--------------guess_button------------------------------- reik keist obvs
void Game::OnGuess(wxCommandEvent& e)
{
   std::string strWord = inputBox->GetValue().ToStdString();
   if (strWord.length() < 5) {
       wxMessageBox("Word is too short");
       return;
   }
   if (strWord.length() > 5) {
       wxMessageBox("Word is too long");
       return;
   }
   if (!isWord(strWord)) {
       wxMessageBox("Not a word!");
       return;
   }

   for (int i = lettersInWord * guessNumber; i < lettersInWord * guessNumber + lettersInWord; i++){

      boxes[i]->SetLabel(strWord[i - lettersInWord * guessNumber]);
       if (letterInPos(i - lettersInWord * guessNumber, strWord[i - lettersInWord * guessNumber]))
       {
           boxes[i]->SetBackgroundColour(green);
           if (guessNumber == 5) score++;
       }
       else if (letterExist(strWord[i - lettersInWord * guessNumber])) boxes[i]->SetBackgroundColour(yellow);
   }
    grid->Layout();
   if (strWord == corrWord) {               //reik paendint cia
       score = (maxScore - guessNumber * 5);
       if(player) dataBase.addPoints(score, player->getID());
       wxMessageBox("Correct! You get " + std::to_string(score) + " points!");
       return;
   }
    guessNumber++;
    if (guessNumber >= guessCount) {
        wxMessageBox("You lost!\nCorrect answer: " + corrWord +"\nPoints received : " + std::to_string(score));         //cia irgi reikai endint nes pralosia
        return;
    }
    e.Skip();
}
bool Game::isWord(std::string guessedWord) {
    for (int i = 0; i < wordList.size(); i++)
        if (guessedWord == wordList[i]) return true;
    return false;
}
void Game::wordGen(std::string fvardas) {
    std::ifstream fin(fvardas);
    while (!fin.eof())
    {
        std::string temp;
        fin >> temp;
        trim(temp);
        if(temp.length() != 0)
            wordList.push_back(temp);
    }
    std::uniform_int_distribution<int> dist(0, wordList.size()-1);
    corrWord = wordList[dist(mt)];
}
bool Game::letterInPos(int pos, char letter) {
    if (letter == corrWord[pos]) return true;
    return false;
}
bool Game::letterExist(char letter) {
    for (int i = 0; i < corrWord.length(); i++)
        if (letter == corrWord[i]) return true;
    return false;
}
