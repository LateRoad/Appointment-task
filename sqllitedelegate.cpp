#include "sqllitedelegate.h"

SQLLiteDelegate::SQLLiteDelegate()
    : database(QSqlDatabase())
{

}

void SQLLiteDelegate::setDatabase() {
    this->database = QSqlDatabase::addDatabase("QSQLITE");
    this->database.setDatabaseName(QCoreApplication::applicationDirPath() + "/users.db");
    this->database.open();
    QSqlQuery query;
        query.exec("SELECT _id, Login, Password, Name, Surname, Permission FROM User");
        if (!query.next()) {
            query.exec(
                        "CREATE TABLE User ("
                        " _id	 INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                        "Login TEXT NOT NULL,"
                        "Password	INTEGER NOT NULL,"
                        "Name	TEXT,"
                        "Surname	TEXT,"
                        "Permission	INTEGER NOT NULL)"
                        );
            query.exec("INSERT INTO User"
                       " VALUES ('1', 'admin', 'admin', 'Roman', 'Pozdnyakov', '1');");
            query.exec("SELECT _id, Login, Password, Name, Surname, Permission FROM User");
    }
}


QSqlQuery SQLLiteDelegate::getQuery() {
    QSqlQuery query;
        query.exec("SELECT _id, Login, Password, Name, Surname, Permission FROM User");
    return query;
}

void SQLLiteDelegate::close() {
    this->database.close();
}
