#include "leaderboard.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Leaderboard::Leaderboard(const wxString& title) : wxDialog(NULL, wxID_ANY, title,
    wxDefaultPosition, wxSize(370, 350))
{


    wxStaticText* heading = new wxStaticText(this, wxID_ANY, wxT("The Leaderboard"),
        wxPoint(30, 15));


    wxStaticLine* sl1 = new wxStaticLine(this, wxID_ANY, wxPoint(25, 50),
        wxSize(300, 1));

    wxStaticText* st1 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 80));
    wxStaticText* st2 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 100));
    wxStaticText* st3 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 120));
    wxStaticText* st4 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 140));
    wxStaticText* st5 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 160));
    wxStaticText* st6 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 180));
    wxStaticText* st7 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 200));
    wxStaticText* st8 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 220));
    wxStaticText* st9 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 240));
    wxStaticText* st10 = new wxStaticText(this, wxID_ANY, wxT(" - "),
        wxPoint(25, 260));

    wxStaticText* st21 = new wxStaticText(this, wxID_ANY, wxT("1"),
        wxPoint(10, 80));
    wxStaticText* st22 = new wxStaticText(this, wxID_ANY, wxT("2"),
        wxPoint(10, 100));
    wxStaticText* st23 = new wxStaticText(this, wxID_ANY, wxT("3"),
        wxPoint(10, 120));
    wxStaticText* st24 = new wxStaticText(this, wxID_ANY, wxT("4"),
        wxPoint(10, 140));
    wxStaticText* st25 = new wxStaticText(this, wxID_ANY, wxT("5"),
        wxPoint(10, 160));
    wxStaticText* st26 = new wxStaticText(this, wxID_ANY, wxT("6"),
        wxPoint(10, 180));
    wxStaticText* st27 = new wxStaticText(this, wxID_ANY, wxT("7"),
        wxPoint(10, 200));
    wxStaticText* st28 = new wxStaticText(this, wxID_ANY, wxT("8"),
        wxPoint(10, 220));
    wxStaticText* st29 = new wxStaticText(this, wxID_ANY, wxT("9"),
        wxPoint(10, 240));
    wxStaticText* st210 = new wxStaticText(this, wxID_ANY, wxT("10"),
        wxPoint(10, 260));


    wxStaticText* st11 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 80), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st12 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 100), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st13 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 120), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st14 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 140), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st15 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 160), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st16 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 180), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st17 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 200), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st18 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 220), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st19 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 240), wxSize(90, -1), wxALIGN_RIGHT);
    wxStaticText* st20 = new wxStaticText(this, wxID_ANY, wxT("0"),
        wxPoint(220, 260), wxSize(90, -1), wxALIGN_RIGHT);

    wxStaticLine* sl2 = new wxStaticLine(this, wxID_ANY, wxPoint(25, 280),
        wxSize(300, 1));


    this->Centre();
}