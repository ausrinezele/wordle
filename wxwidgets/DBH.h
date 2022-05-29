#pragma once
#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include <wx/wx.h>
#include "user.h"


class DBH
{
public:
	DBH();
	~DBH();
	
	void addUser(std::string name, std::string email, std::string password);
	void addWord(std::string word);
	void addPoints(int points, int userID);

	User* findUser(std::string nickname, std::string password);

	std::vector<User> getLeaders();

	std::vector<std::string> getAllNames();
	std::vector<std::string> getAllEmails();
	std::vector<std::string> getAllWords();
private:
	const std::string server = "sql11.freemysqlhosting.net";
	const std::string username = "sql11496150";
	const std::string password = "8ItJc4CPsr";

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;
};


