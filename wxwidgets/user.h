#pragma once
#include <iostream>
#include <vector>

class User
{
public:
	User();
	User(std::string nick, int uID);
	~User();

	void setNick(std::string &nick);
	void setUserId(int uID);
	void setScores(std::vector<int> &sc);

	int getID() const;

private:
	std::string nickname;
	int UserID;
	std::vector<int> scores;
};