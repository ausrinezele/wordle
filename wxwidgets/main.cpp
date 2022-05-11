#include "main.h"
#include "game.h"
#include "leaderboard.h"
#include "rules.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Game* game = new Game(wxT("Game"));
    game->Show(true);
    
    return true;
}