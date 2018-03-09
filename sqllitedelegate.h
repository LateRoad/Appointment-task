#ifndef SQLLITEDELEGATE_H
#define SQLLITEDELEGATE_H

#include <QtSql>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

class SQLLiteDelegate
{
public:
    SQLLiteDelegate();
    QSqlQuery getQuery();
    void setDatabase();
    void close();

private:
    QSqlDatabase database;
};

#endif // SQLLITEDELEGATE_H
