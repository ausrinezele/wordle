#include "score.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Score::Score(const wxString& title) : wxDialog(NULL, wxID_ANY, title,
    wxDefaultPosition, wxSize(200, 100))
{

    wxStaticText* l1 = new wxStaticText(this, wxID_ANY, wxT("-"), wxPoint(15, 15));
    wxStaticText* l2 = new wxStaticText(this, wxID_ANY, wxT("-"), wxPoint(160, 15));
    this->Centre();
}