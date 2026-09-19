#include "Database.h"

Database::Database() {

    try {

        driver = sql::mysql::get_mysql_driver_instance();

        con = driver->connect(
            "tcp://127.0.0.1:3306",
            "root",
            "admin"
        );

        con->setSchema("banking_system");

        cout << "Database Connected Successfully!\n";

    }
    catch(sql::SQLException &e) {

        cout << "Connection Error: "
             << e.what()
             << endl;
    }
}

sql::Connection* Database::getConnection() {

    return con;
}