#ifndef DIALOGENTRANCE_H
#define DIALOGENTRANCE_H

#include <QDialog>

namespace Ui {
class DialogEntrance;
}

class DialogEntrance : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEntrance(QWidget *parent = 0);
    ~DialogEntrance();

    void showErrorLabel(int errorCode);

private slots:
    void on_buttonSignIn_clicked();
    void on_buttonSignUp_clicked();

    void on_labelHide_in_linkActivated(const QString &link);

    void on_labelHide_in_linkHovered(const QString &link);

signals:
    void buttonSignInClicked(QString, QString);
    void buttonSignUpClicked(QString, QString);
    void createButtonPressed(QStringList);

private:
    Ui::DialogEntrance *ui;
};

#endif // DIALOGENTRANCE_H
