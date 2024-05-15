#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    QIcon icon(":/Imagine/imagine/icon.ico"); // Путь к вашей иконке в ресурсах
    a.setWindowIcon(icon);
    w.show();

    return a.exec();
}
