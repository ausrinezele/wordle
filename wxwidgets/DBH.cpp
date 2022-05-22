#include "DBH.h"


DBH::DBH():driver(nullptr),con(nullptr),stmt(nullptr),pstmt(nullptr),res(nullptr)
{
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password); // prisiconnectina prie serverio
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }
    con->setSchema("sql11494207"); // sukuria connectiona i butent ta duombaze
}

DBH::~DBH()
{
    delete pstmt;
    delete con;
}
void DBH::addUser(std::string name, std::string email, std::string password) {
    pstmt = con->prepareStatement("INSERT INTO users (nickname, email, password) VALUES(?,?,?)"); // apsaugo nuo sql injectionu
    pstmt->setString(1, name);
    pstmt->setString(2, email);
    pstmt->setString(3, password);
    pstmt->execute();
    wxMessageBox("Registered!");
}

void DBH::addPoints(int points, int userID) {
    pstmt = con->prepareStatement("UPDATE users SET points = points + (?) WHERE user_id = (?)");
    pstmt->setInt(1, points);
    pstmt->setInt(2, userID);
    pstmt->execute();
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
User* DBH::findUser(std::string nickname, std::string password) {
    pstmt = con->prepareStatement("SELECT nickname, password, user_id, points FROM users");
    res = pstmt->executeQuery();

    while (res->next())
    {
        if (nickname == res->getString("nickname") && password == res->getString("password"))
            return new User(nickname,res->getInt("user_id"), res->getInt("points"));
    }
    return nullptr;
}
std::vector<User> DBH::getLeaders() {
    pstmt = con->prepareStatement("SELECT nickname, user_id, points FROM users ORDER BY points DESC limit 10");
    res = pstmt->executeQuery();
    std::vector<User> leaders;
    while (res->next())
    {
        leaders.emplace_back(res->getString("nickname"), res->getInt("user_id"), res->getInt("points"));
    }
    return leaders;
}
