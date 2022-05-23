#include "word.h"
#include <wx/stattext.h>
#include <wx/statline.h>
#include <fstream>

void Word::addWordToDb()
{
    std::ifstream fin("zodiai.txt");
    while (!fin.eof())
    {
        std::string temp;
        fin >> temp;
        trim(temp);
        if (temp.length() != 0)
            dataBase.addWord(temp);
    }
}
void Word::ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
void Word::rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
void Word::trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}
