#include "user.h"

User::User() : nickname(""), UserID(-1)
{
}
User::User(std::string nick, int uID) : nickname(nick), UserID(uID)
{
}
User::~User()
{
}

void User::setNick(std::string &nick) {
	nickname = nick;
}
void User::setUserId(int uID) {
	UserID = uID;
}
void User::setScores(std::vector<int> &sc) {
	scores = sc;
};

int User::getID() const {
	return UserID;
}