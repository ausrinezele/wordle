#include "score.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Score::Score(const wxString& title) : wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(200, 100))
{
    name = new wxStaticText(this, wxID_ANY, wxT("-"), wxPoint(15, 15));
    score = new wxStaticText(this, wxID_ANY, wxT("-"), wxPoint(160, 15));
    this->Centre();
}
void Score::setScore(int sc) {
    score->SetLabel(std::to_string(sc));
}
void Score::setName(std::string username) {
    name->SetLabel(username);
}
