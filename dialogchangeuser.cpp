#include "dialogchangeuser.h"
#include "ui_dialogchangeuser.h"

DialogChangeUser::DialogChangeUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChangeUser)
{
    ui->setupUi(this);
}

DialogChangeUser::~DialogChangeUser()
{
    delete ui;
}

void DialogChangeUser::setUserData(QStringList user)
{
    ui->nameField->setText(user[0]);
    ui->surnameField->setText(user[1]);
    ui->loginField->setText(user[2]);
}

void DialogChangeUser::showChangeWindow()
{
    ui->createButton->setText("Change");
    this->show();
}

void DialogChangeUser::on_cancelButton_clicked()
{
    this->close();
}

void DialogChangeUser::on_createButton_clicked()
{
    QStringList list;
    list.append(ui->nameField->text());
    list.append(ui->surnameField->text());
    list.append(ui->loginField->text());
    list.append(ui->passwordField->text());
    list.append(ui->repeatField->text());

    emit createButtonPressed(list);
}
