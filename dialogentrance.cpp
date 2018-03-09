#include "dialogentrance.h"
#include "ui_dialogentrance.h"

DialogEntrance::DialogEntrance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEntrance)
{
    ui->setupUi(this);
    ui->tabWidget->setStyleSheet(
                "QTabBar::tab:selected { min-width:250px; min-height:70px; color: #507299; border: #D2D8D8; background: #FFFFFF; }"
                "QTabBar::tab{ min-width:250px; min-height:70px; background: #D2D8D8;  color: #507299; }");
    ui->boxLogin_in->setStyleSheet(
                "QGroupBox { border: 1px solid  #D2D8D8; border-radius: 5px; }");
    ui->boxPassword_in->setStyleSheet(
                "QGroupBox { border: 1px solid  #D2D8D8; border-radius: 5px; }");
    ui->boxLogin_up->setStyleSheet(
                "QGroupBox { border: 1px solid  #D2D8D8; border-radius: 5px; }");
    ui->boxPassword_up->setStyleSheet(
                "QGroupBox { border: 1px solid  #D2D8D8; border-radius: 5px; }");

    ui->tabWidget->setCurrentIndex(0);
    ui->lineLogin_in->setPlaceholderText("E-mail");
    ui->linePassword_in->setPlaceholderText("Пароль");
    ui->lineLogin_up->setPlaceholderText("E-mail");
    ui->linePassword_up->setPlaceholderText("Пароль");
    ui->lineLogin_in->setText("admin");
    ui->linePassword_in->setText("admin");
}

DialogEntrance::~DialogEntrance()
{
    delete ui;
}
/*DialogEntrance::validateFields()
{
    bool isAllFieldsValid = true;
    if (QRegExp("[a-zA-Z]{2,15}").exactMatch(ui->lineLogin_in->text())) {
        ui->errorLabel->setPixmap(QPixmap(":/new/images/images/success.png"));
    }
    else {
        isAllFieldsValid = false;
        ui->errorLabel->setPixmap(QPixmap(":/new/images/images/error.png"));
    }
    if (QRegExp("[a-zA-Z]{2,15}").exactMatch(ui->surnameField->text())) {
        ui->errorLabel_2->setPixmap(QPixmap(":/new/images/images/success.png"));
    }
    else {
        isAllFieldsValid = false;
        ui->errorLabel_2->setPixmap(QPixmap(":/new/images/images/error.png"));
    }
    if (QRegExp("[a-zA-Z0-9_-]{3,13}").exactMatch(ui->loginField->text())) {
        ui->errorLabel_3->setPixmap(QPixmap(":/new/images/images/success.png"));
    }
    else {
        isAllFieldsValid = false;
        ui->errorLabel_3->setPixmap(QPixmap(":/new/images/images/error.png"));
    }
    if (QRegExp("[a-zA-Z0-9_-]{5,20}").exactMatch(ui->passwordField->text())) {
        ui->errorLabel_4->setPixmap(QPixmap(":/new/images/images/success.png"));
    }
    else {
        isAllFieldsValid = false;
        ui->errorLabel_4->setPixmap(QPixmap(":/new/images/images/error.png"));
    }
    if (ui->passwordField->text() == ui->repeatField->text()) {
        ui->errorLabel_5->setPixmap(QPixmap(":/new/images/images/success.png"));
    }
    else {
        isAllFieldsValid = false;
        ui->errorLabel_5->setPixmap(QPixmap(":/new/images/images/error.png"));
    }
    return isAllFieldsValid;
}*/

void DialogEntrance::on_buttonSignIn_clicked()
{
    emit buttonSignInClicked(ui->lineLogin_in->text(), ui->linePassword_in->text());
}

void DialogEntrance::on_buttonSignUp_clicked()
{
    emit buttonSignUpClicked(ui->lineLogin_up->text(), ui->linePassword_up->text());
}


void DialogEntrance::showErrorLabel(int errorCode)
{
    if (errorCode == 1) {
        ui->labelError->setText("Заполните все поля!");
    } else if (errorCode == 2) {
        ui->labelError->setText("Неверный пароль!");
    }

}

void DialogEntrance::on_labelHide_in_linkActivated(const QString &link)
{
    if(ui->linePassword_in->echoMode() == QLineEdit::Normal)
        ui->linePassword_in->setEchoMode(QLineEdit::Password);
    if(ui->linePassword_in->echoMode() == QLineEdit::Password)
        ui->linePassword_in->setEchoMode(QLineEdit::Normal);

}

void DialogEntrance::on_labelHide_in_linkHovered(const QString &link)
{
            ui->linePassword_in->setEchoMode(QLineEdit::Password);
}
