#ifndef WINDOWSLORD_H
#define WINDOWSLORD_H

#include <QObject>
#include "windowmain.h"
#include "dialogentrance.h"

enum StateUser
{
    USER,
    ADMIN
};

class WindowsLord: public QObject
{
        Q_OBJECT

public:
    explicit WindowsLord(QObject *parent = 0);
    ~WindowsLord();

    void showAutorization(){ dialogEntrance->show(); }
    void showProgram(){ windowMain->show(); }
    void updateDatabase();
    void setUsers(QVector<User>);

private slots:
    void buttonSignInClicked(QString, QString);
    void buttonSignUpClicked(QString, QString);
    void slotUpdateDataBase();

private:
    DialogEntrance *dialogEntrance;
    WindowMain *windowMain;
    StateUser stateUser;
    QVector<User> users;
    SQLLiteDelegate database;
    User currentUser;
};

#endif // WINDOWSLORD_H
