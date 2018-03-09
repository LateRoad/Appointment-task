#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <QMainWindow>
#include "appointment.h"
#include "dialogchangeuser.h"


namespace Ui {
class WindowMain;
}

class WindowMain : public QMainWindow
{
    Q_OBJECT
    friend class Appointment;

public:
    explicit WindowMain(QWidget *parent = 0);
    ~WindowMain();

    friend class WindowsLord;
     void setUsers(QVector<User>);

protected slots:
    //                            GroupBox buttons' slots ( QCommandLinkButtons )
    void on_buttonHome_clicked();
    void on_buttonSettings_clicked();
    void on_buttonAppointment_clicked();
    void on_buttonExit_clicked();
    //                             Buttons' slots ( Just pushButtons )
    void on_buttonToSolve_clicked();
    //                             SpinBoxes' slots
    void on_vacancyBox_valueChanged(int arg1);
    void on_candidateBox_valueChanged(int arg1);
    //                             Internal methods ( Need for solution NFS(Kek) :) )
    void setMatrixItems();
    //                             Design/Program settings and themes
    void themeBlue();
    void settingsMain();
    //                             Methods for Settings Page
    void on_buttonDBedit_clicked();
    void on_pushButton_clicked();

    void labelsHomeChange(User);
    void rightClickMenu(QPoint);
    void removeUserData();
    void changeUserData();
private slots:
    void on_pushButton_2_clicked();
    void on_lineLogin_textChanged(const QString &arg1);
    void on_lineName_textChanged(const QString &arg1);
    void on_lineSurname_textChanged(const QString &arg1);
    void changeUser(QStringList);
    void on_pushButton_3_clicked();
signals:
    void signalUpdateDataBase();
protected:
    Ui::WindowMain *ui;
    Appointment appointment;
    QPoint selectedRow;
    SQLLiteDelegate database;
    QVector<User> users;
    bool buttonEditState = true;
    User currentUser;
    User tempUser;
    DialogChangeUser *changeUserDialog;
};

#endif // WINDOWMAIN_H
