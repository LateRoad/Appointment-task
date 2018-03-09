#include "windowmain.h"
#include "ui_windowmain.h"
#include "dialogentrance.h"

//
//                                                          Delegate class for tableWidget's items (for regular expression)
//

class Delegate : public QItemDelegate
{
public:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &,
                      const QModelIndex &) const
    {
        //
        //                         Set validator
        QLineEdit *lineEdit = new QLineEdit(parent);
        QIntValidator *validator = new QIntValidator(lineEdit);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
};

//
//                                                          Constructor, destructor of ProgramWindow
//

WindowMain::WindowMain(QWidget *parent) :
    QMainWindow(parent),
    changeUserDialog(new DialogChangeUser),
    database(SQLLiteDelegate()),
    ui(new Ui::WindowMain)
{
    ui->setupUi(this);
    this->settingsMain();
    ui->tableWidget_2->setColumnCount(6);
    ui->tableWidget_2->setRowCount(1);

     ui->tableWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
     connect(ui->tableWidget_2, SIGNAL(customContextMenuRequested(QPoint)), SLOT(rightClickMenu(QPoint)));
     ui->lineLogin->setEnabled(false);
     ui->linePermission->setEnabled(false);
     ui->lineNewPassword->hide();
     ui->lineName->hide();
     ui->lineSurname->hide();
     ui->linePrevPassword->hide();
     ui->labelNameEdit->hide();
     ui->labelSurnameEdit->hide();
     ui->labelNewPassword->hide();
     ui->labelPrevPassword->hide();

     QStringList userLabels;
     userLabels.append("ID");
     userLabels.append("Logins");
     userLabels.append("Password");
     userLabels.append("Names");
     userLabels.append("Surnames");
     userLabels.append("Permission");
     ui->tableWidget_2->setHorizontalHeaderLabels(userLabels);
}

WindowMain::~WindowMain()
{
    delete ui;
}

//
//                                                          GroupBox buttons' slots ( QCommandLinkButtons )
//

void WindowMain::on_buttonHome_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void WindowMain::on_buttonSettings_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void WindowMain::on_buttonAppointment_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void WindowMain::on_buttonDBedit_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void WindowMain::on_buttonExit_clicked()
{
    close();
}

void WindowMain::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//
//                                                          Buttons' slots ( Just pushButtons )
//

void WindowMain::on_buttonToSolve_clicked()
{
    setMatrixItems();
    appointment.makeSolution();
    //
    //                         Show the answer of Appointment task
    QMessageBox *msg = new QMessageBox(this);
    QString view;
    view = QString::number(appointment.getSolution());
    msg->setText(view);
    msg->show();
    //
    //                        Set style for items which is part of answer
                                                                                                                                                       //TODO
    //for(int i = 0; i < 10; i++)
    //    ui->tableWidget->item(getFirstItem(i), getSecondItem(i))->setBackgroundColor("#b8c8d9");
}

//
//                                                          SpinBoxes' slots
//

void WindowMain::on_vacancyBox_valueChanged(int arg1)
{
    appointment.setVacancy(arg1);
    //
    //                         Here tableWidget's settings are changing
    ui->tableAppointment->setColumnCount(appointment.getVacancy());
    //                         Just for design :) For scretching the header of tableWidget
    QHeaderView *header = ui->tableAppointment->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
}

void WindowMain::on_candidateBox_valueChanged(int arg1)
{
    appointment.setCandidates(arg1);
    //
    //                         Here tableWidget's settings are changing
    ui->tableAppointment->setRowCount(appointment.getCandidates());
}

//
//                                                          Internal methods ( Need for solution NFS(Kek) :) )
//

void WindowMain::setMatrixItems()
{
    for(int i = 0; i < appointment.getCandidates(); i++)
    {
        for(int j = 0; j < appointment.getVacancy(); j++)
             appointment.setItem(i, j, ui->tableAppointment->item(i, j)->text().toInt());
    }
}

//
//                                                          Design/Program settings and themes
//

void WindowMain::settingsMain()
{
    this->themeBlue();
    //
    //                         stackedWidget's settings
    ui->stackedWidget->setCurrentIndex(0);
    //
    //                         tableWidget's settings
    ui->tableAppointment->setRowCount(appointment.getCandidates());
    ui->tableAppointment->setColumnCount(appointment.getVacancy());

    QHeaderView *header = ui->tableAppointment->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableAppointment->setItemDelegate(new Delegate);
}

void WindowMain::themeBlue()
{
    //
    //                         CSS of QCommandLinkButtons
    ui->buttonAppointment->setStyleSheet(
                "QCommandLinkButton:hover {background-color: #305075; }"
                "QCommandLinkButton {color: #b8c8d9;}");
    ui->buttonSettings->setStyleSheet(
                "QCommandLinkButton:hover {background-color: #305075; }"
                "QCommandLinkButton {color: #b8c8d9;}");
    ui->buttonHome->setStyleSheet(
                "QCommandLinkButton:hover {background-color: #305075; }"
                "QCommandLinkButton {color: #b8c8d9;}");
    ui->buttonExit->setStyleSheet(
                "QCommandLinkButton:hover {background-color: #305075; }"
                "QCommandLinkButton {color: #b8c8d9;}");

    //
    //                         CSS of QPushButtons
    ui->buttonToSolve->setStyleSheet(
                "QPushButton:hover {background-color: #b8c8d9; border-color: #EDEEF0; border: 0px #EDEEF0 #EDEEF0; }"
                "QPushButton {color: #305075; border-color: #EDEEF0; border: 0px #EDEEF0 #EDEEF0; }");
}


//
//                                                          Database methods
//

void WindowMain::setUsers(QVector<User> users)
{
    this->users = users;
    ui->tableWidget_2->setRowCount(users.count());
    for (int i = 0; i < users.count(); i++)
    {
        QTableWidgetItem *item0 = new QTableWidgetItem;
        QTableWidgetItem *item1 = new QTableWidgetItem;
        QTableWidgetItem *item2 = new QTableWidgetItem;
        QTableWidgetItem *item3 = new QTableWidgetItem;
        QTableWidgetItem *item4 = new QTableWidgetItem;
        QTableWidgetItem *item5 = new QTableWidgetItem;

        item0->setText(users[i]._id);
        item1->setText(users[i].login);
        item2->setText(users[i].password);
        item3->setText(users[i].name);
        item4->setText(users[i].surname);
        item5->setText(users[i].permission);

        ui->tableWidget_2->setItem(i, 0, item0);
        ui->tableWidget_2->setItem(i, 1, item1);
        ui->tableWidget_2->setItem(i, 2, item2);
        ui->tableWidget_2->setItem(i, 3, item3);
        ui->tableWidget_2->setItem(i, 4, item4);
        ui->tableWidget_2->setItem(i, 5, item5);
    }
}

void WindowMain::labelsHomeChange(User currentUser)
{
    this->currentUser = currentUser;
    this->tempUser = currentUser;
    QString permission = "User";
    if(currentUser.permission == "1")
        permission = "Admin";
    ui->labelName->setText(currentUser.name + " " + currentUser.surname);
    ui->lineLogin->setText(currentUser.login);
    ui->labelPermission->setText(permission);
    ui->labelPermission_2->setText(permission);
    ui->linePermission->setText(permission);

    ui->lineName->setText(currentUser.name);
    ui->lineSurname->setText(currentUser.surname);
}

void WindowMain::rightClickMenu(QPoint point)
{
    QMenu *menu=new QMenu(this);

    menu->addAction("Remove", this, SLOT(removeUserData()));
    menu->addAction("Change", this, SLOT(changeUserData()));
    menu->popup(ui->tableWidget_2->viewport()->mapToGlobal(point));

    this->selectedRow = point;
}

void WindowMain::removeUserData()
{
    QModelIndex index = ui->tableWidget_2->indexAt(this->selectedRow);
    this->database.setDatabase();
    QSqlQuery query = this->database.getQuery();
    QString login = ui->tableWidget_2->item(index.row(), 1)->text();
    for (int i = 0; i < this->users.count(); i++) {
        if (login == this->users[i].login)
            this->users.remove(i);
    }
    query.exec("DELETE FROM User"
               " WHERE Login='" + ui->tableWidget_2->item(index.row(), 1)->text() + "';");
    this->database.close();
    ui->tableWidget_2->removeRow(index.row());
}

void WindowMain::changeUserData()
{
   QModelIndex index = ui->tableWidget_2->indexAt(this->selectedRow);    // when user clicked right-menu
   QStringList userToChange;
   QString login = ui->tableWidget_2->item(index.row(), 1)->text();
   for (int i = 0; i < this->users.count(); i++) {
       if (login == this->users[i].login) {
           userToChange.push_back(this->users[i].name);
           userToChange.push_back(this->users[i].surname);
           userToChange.push_back(this->users[i].login);
           tempUser.login = users[i].login;

           connect(this->changeUserDialog, SIGNAL(createButtonPressed(QStringList)), this, SLOT(changeUser(QStringList)));
           this->changeUserDialog->setUserData(userToChange);
           this->changeUserDialog->showChangeWindow();
           break;
       }
   }
}


void WindowMain::changeUser(QStringList list)
{
   // QModelIndex index = ui->tableWidget_2->indexAt(this->selectedRow);    //when user clicked change in dialog

    for (int i = 0; i < this->users.count(); i++) {
        if (list[0] == this->users[i].login) {
            for (int j = 0; j < this->users.count(); j++){
                if (list[0] == this->users[j].login && j != i) {
                    QMessageBox::critical(this->changeUserDialog, "", tr("Error!\nUser with this login is already exist."));
                    return;
                }
            }
        }
            this->database.setDatabase();
            QSqlQuery query = this->database.getQuery();
                query.exec(
                           "UPDATE User"
                           " SET "
                           "Login = '" + list[2] + "', "
                           "Name ='" + list[0] + "', "
                           "Surname ='" + list[1] + "' WHERE Login='" + tempUser.login + "';");
            this->setUsers(this->users);
            this->database.close();
            break;
    }
    this->changeUserDialog->close();
}
void WindowMain::on_pushButton_2_clicked()
{
    if(buttonEditState)
    {
        ui->lineLogin->setEnabled(true);
        ui->linePermission->setEnabled(true);
        ui->lineNewPassword->show();
        ui->lineName->show();
        ui->lineSurname->show();
        ui->linePrevPassword->show();
        ui->labelNameEdit->show();
        ui->labelSurnameEdit->show();
        ui->labelNewPassword->show();
        ui->labelPrevPassword->show();
        ui->pushButton_2->setText("Применить");
        buttonEditState = false;
    }
    else if(!buttonEditState)
    {
        ui->lineLogin->setEnabled(false);
        ui->linePermission->setEnabled(false);
        ui->lineNewPassword->hide();
        ui->lineName->hide();
        ui->lineSurname->hide();
        ui->linePrevPassword->hide();
        ui->labelNameEdit->hide();
        ui->labelSurnameEdit->hide();
        ui->labelNewPassword->hide();
        ui->labelPrevPassword->hide();
        ui->pushButton_2->setText("Изменить");
        buttonEditState = true;

        for (int i = 0; i < this->users.count(); i++) {
            if (ui->lineLogin->text() == this->users[i].login) {
                for (int j = 0; j < this->users.count(); j++){
                    if (ui->lineLogin->text() == this->users[j].login && j != i) {
                        QMessageBox::critical(this->changeUserDialog, "", tr("Error!\nUser with this login is already exist."));
                        return;
                    }
                }
            }
                this->database.setDatabase();
                QSqlQuery query = this->database.getQuery();
                    query.exec(
                               "UPDATE User"
                               " SET "
                               "Login = '" + ui->lineLogin->text() + "', "
                               "Name ='" + ui->lineName->text() + "', "
                               "Surname ='" + ui->lineSurname->text() + "' WHERE Login ='" + currentUser.login + "';");
                this->setUsers(this->users);
                this->database.close();
                break;
        }
    }
    currentUser.login = ui->lineLogin->text();
    currentUser.name = ui->lineName->text();
    currentUser.surname = ui->lineSurname->text();
    labelsHomeChange(this->currentUser);
}

void WindowMain::on_lineLogin_textChanged(const QString &arg1)
{
    tempUser.login = arg1;
}

void WindowMain::on_lineName_textChanged(const QString &arg1)
{
    tempUser.name = arg1;
}

void WindowMain::on_lineSurname_textChanged(const QString &arg1)
{
    tempUser.surname = arg1;
}

void WindowMain::on_pushButton_3_clicked()
{
     emit signalUpdateDataBase();
}
