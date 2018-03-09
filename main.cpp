#include <QApplication>
#include "windowslord.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WindowsLord lord;
    //If you want to hide the Window Frame decomment this
    //app.setWindowFlags(Qt::FramelessWindowHint);
    lord.showAutorization();
    return a.exec();
}
