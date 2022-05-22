#pragma once
#include <iostream>
#include <vector>

class User
{
public:
	User();
	User(std::string nick, int uID);
	User(std::string nick, int uID, int sc);
	~User();

	void setNick(std::string &nick);
	void setUserId(int uID);
	void setScore(int sc);

	int getID() const;
	std::string getNick() const;
	int getScore();

private:
	std::string nickname;
	int UserID;
	int score;
};