#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <mysql/jdbc.h>

using namespace std;

class Database {

private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

public:
    Database();

    sql::Connection* getConnection();
};

#endif