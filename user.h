#ifndef USER_H
#define USER_H

#include <QString>

struct User {
    QString _id;
    QString login;
    QString password;
    QString name;
    QString surname;
    QString permission;

    User()
    {
        this->_id = "";
        this->login = "";
        this->password = "";
        this->name = "";
        this->surname = "";
        this->permission = "";
    }

    User(
            QString newId,
            QString newLogin,
            QString newPassword,
            QString newName,
            QString newSurname,
            QString newPermission)
    {
        this->_id = newId;
        this->login = newLogin;
        this->password = newPassword;
        this->name = newName;
        this->surname = newSurname;
        this->permission = newPermission;
    }
};

#endif // USERS_H
