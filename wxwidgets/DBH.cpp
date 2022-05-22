#include "DBH.h"


DBH::DBH():driver(nullptr),con(nullptr),stmt(nullptr),pstmt(nullptr),res(nullptr)
{
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }

    con->setSchema("sql11494207"); // sukuria conectiona

    wxMessageBox("connected");
}

DBH::~DBH()
{
    delete pstmt;
    delete con;
}
void DBH::addUser(std::string name, std::string email, std::string password) {
    pstmt = con->prepareStatement("INSERT INTO users (nickname, email, password) VALUES(?,?,?)");
    pstmt->setString(1, name);
    pstmt->setString(2, email);
    pstmt->setString(3, password);
    pstmt->execute();
    wxMessageBox("new user set");
}

void DBH::addPoints(int points, int userID) {
    pstmt = con->prepareStatement("UPDATE users SET points = points + (?) WHERE user_id = (?)");
    pstmt->setInt(1, points);
    pstmt->setInt(2, userID);
    pstmt->execute();
    wxMessageBox("points added");
}

std::vector<std::string> DBH::getAllNames() {
    pstmt = con->prepareStatement("SELECT nickname FROM users");
    res = pstmt->executeQuery();

    std::vector<std::string> temp;

    while (res->next())
        temp.push_back(res->getString("nickname"));
    return temp;
}
std::vector<std::string> DBH::getAllEmails(){
    pstmt = con->prepareStatement("SELECT email FROM users");
    res = pstmt->executeQuery();

    std::vector<std::string> temp;

    while (res->next())
        temp.push_back(res->getString("email"));
    return temp;
}
int DBH::findUser(std::string nickname, std::string password) {
    pstmt = con->prepareStatement("SELECT nickname, password, user_id FROM users");
    res = pstmt->executeQuery();

    while (res->next())
    {
        if (nickname == res->getString("nickname") && password == res->getString("password"))
            return res->getInt("user_id");
    }
    return 0;
}
