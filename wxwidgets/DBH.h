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
	void addPoints(int points, int userID);
	User* findUser(std::string nickname, std::string password);

	std::vector<std::string> getAllNames();
	std::vector<std::string> getAllEmails();
private:
	const std::string server = "sql11.freemysqlhosting.net";
	const std::string username = "sql11494207";
	const std::string password = "2LwdPnYQla";

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;
};


