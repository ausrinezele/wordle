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


void DBH::runConnection()
{
    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS inventory");
    //cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
    //cout << "Finished creating table" << endl;
    delete stmt;

    pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();
    //cout << "One row inserted." << endl;

    pstmt->setString(1, "orange");
    pstmt->setInt(2, 154);
    pstmt->execute();
    //cout << "One row inserted." << endl;

    pstmt->setString(1, "apple");
    pstmt->setInt(2, 100);
    pstmt->execute();
    //cout << "One row inserted." << endl;

    wxMessageBox("all inserted");
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
    pstmt = con->prepareStatement("INSERT INTO user_points (points,user_id) VALUES(?,?)");
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
