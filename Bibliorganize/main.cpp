#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPainter>
#include <QLabel>
#include <string>







int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/LIVRO/images.png"));
    w.show();

    return a.exec();
}
