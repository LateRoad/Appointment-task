#ifndef DIALOGCHANGEWUSER_H
#define DIALOGCHANGEUSER_H

#include <QDialog>
#include <QRegExp>

namespace Ui {
class DialogChangeUser;
}

class DialogChangeUser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChangeUser(QWidget *parent = 0);
    ~DialogChangeUser();
    void setUserData(QStringList);
    void showChangeWindow();

private slots:
    void on_cancelButton_clicked();
    void on_createButton_clicked();

//    void on_nameField_cursorPositionChanged(int arg1, int arg2);

signals:
    void createButtonPressed(QStringList);

private:
    Ui::DialogChangeUser *ui;
};

#endif // DIALOGCHANGEUSER_H
