#include "rules.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Rules::Rules(const wxString& title) : wxDialog(NULL, wxID_ANY, title,
    wxDefaultPosition, wxSize(200, 200))
{


    wxStaticText* heading = new wxStaticText(this, wxID_ANY, wxT("Guess a five letter word!"),
        wxPoint(30, 15));


    wxStaticText* st1 = new wxStaticText(this, wxID_ANY, wxT("If a letter is green, it's in the correct place. \n If it is yellow it is in the word, but in a different place. \n If it is black, there's no such letter in the answer."),
        wxPoint(15, 50), wxSize(150, 150), wxALIGN_CENTRE);


    this->Centre();
}