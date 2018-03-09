#include "windowslord.h"

WindowsLord::WindowsLord(QObject *parent)
    : QObject(parent),
      dialogEntrance(new DialogEntrance),
      windowMain(new WindowMain),
      database(SQLLiteDelegate())
{
    connect(this->dialogEntrance, SIGNAL(buttonSignInClicked(QString, QString)), this, SLOT(buttonSignInClicked(QString, QString)));
    connect(this->dialogEntrance, SIGNAL(buttonSignUpClicked(QString, QString)), this, SLOT(buttonSignUpClicked(QString, QString)));
    connect(this->windowMain, SIGNAL(signalUpdateDataBase()), this, SLOT(slotUpdateDataBase()));
    this->updateDatabase();
    this->setUsers(users);
}

WindowsLord::~WindowsLord()
{
    delete this->dialogEntrance;
    delete this->windowMain;
}

void WindowsLord::buttonSignInClicked(QString login, QString password)
{
    if (login.isEmpty() || password.isEmpty())
        this->dialogEntrance->showErrorLabel(1);
    else
    {
        this->currentUser.login = login;
        this->currentUser.password = password;
        int index = -1;
        for(int i = 0; i < this->users.count(); i++)
        {
            if (this->users[i].login == login && this->users[i].password == password)
            {
                index = i;
                this->currentUser = this->users[i];
            }
        }
        if(index == -1)
            this->dialogEntrance->showErrorLabel(2);
        else
        {
            if(currentUser.permission == 1)
                stateUser = ADMIN;
            else
                stateUser = USER;
            this->windowMain->labelsHomeChange(currentUser);
            this->dialogEntrance->close();
            this->showProgram();
        }
    }
}

void WindowsLord::slotUpdateDataBase()
{
    database.close();
    database.setDatabase();
    updateDatabase();
    setUsers(users);
}

void WindowsLord::buttonSignUpClicked(QString login, QString password)
{
    this->users.push_back(User(QString::number(users.size()-1), login, password, " ", " ", "0"));
    this->database.setDatabase();
    QSqlQuery query = this->database.getQuery();
    query.exec("INSERT INTO User (Login, Password, Permission)"
               " VALUES ( '" + login + "', '" + password + "', ' 0');");
    this->database.close();

    this->windowMain->labelsHomeChange(users[users.size()-1]);
    dialogEntrance->close();
    this->showProgram();
}

void WindowsLord::updateDatabase()
{
    this->database.setDatabase();
    QSqlQuery query = this->database.getQuery();
    this->users.clear();
    for (int i = 0; query.next(); i++)
    {
        this->users.push_back(User());
        this->users[i]._id = query.value(0).toString();
        this->users[i].login = query.value(1).toString();
        this->users[i].password = query.value(2).toString();
        this->users[i].name = query.value(3).toString();
        this->users[i].surname = query.value(4).toString();
        this->users[i].permission = query.value(5).toString();
    }
    this->database.close();
}

void WindowsLord::setUsers(QVector<User> users)
{
    this->users = users;
    this->windowMain->setUsers(users);
}
