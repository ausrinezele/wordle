#include "user.h"

User::User() : nickname(""), UserID(-1), score(0)
{
}
User::User(std::string nick, int uID) : nickname(nick), UserID(uID), score(0)
{
}
User::User(std::string nick, int uID, int sc):nickname(nick), UserID(uID), score(sc)
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
void User::setScore(int sc) {
	score = sc;
};

int User::getID() const {
	return UserID;
}
std::string User::getNick() const {
	return nickname;
}
int User::getScore() const {
	return score;
}
