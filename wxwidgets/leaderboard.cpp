#include "leaderboard.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Leaderboard::Leaderboard(const wxString& title) : wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(370, 350))
{
    if (leaders.empty()) leaders = database.getLeaders();
    wxStaticText* heading = new wxStaticText(this, wxID_ANY, wxT("The Leaderboard"), wxPoint(30, 15));
    wxStaticLine* sl1 = new wxStaticLine(this, wxID_ANY, wxPoint(25, 50), wxSize(300, 1));
    for (int i = 0; i < leaders.size() && i < 10; i++) {
       new wxStaticText(this, wxID_ANY, wxT(""+std::to_string(i + 1)), wxPoint(10, 80 + 20*i));
       new wxStaticText(this, wxID_ANY, wxT(" - " + leaders.at(i).getNick()), wxPoint(25, 80 + 20 * i));
       new wxStaticText(this, wxID_ANY, wxT(""+std::to_string(leaders.at(i).getScore())), wxPoint(220, 80+20*i), wxSize(90, -1), wxALIGN_RIGHT);
    }
    wxStaticLine* sl2 = new wxStaticLine(this, wxID_ANY, wxPoint(25, 280), wxSize(300, 1));


    this->Centre();
}