#ifndef GUESTSINFO_H
#define GUESTSINFO_H

#include <QWidget>
#include <QString>
#include "guestsdbutils.cpp"
#include "mainwindow.h"
/*#include <QMessageBox>
#include <QSqlQueryModel>*/

namespace Ui {
    class GuestsInfo;
}

class GuestsInfo : public QWidget
{
    Q_OBJECT

public:
    explicit GuestsInfo(QWidget *parent = 0, QString id = "");
    ~GuestsInfo();
    GuestsDatabaseUtils gstDBUtils;

protected:
   void mousePressEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   QPoint mousePoint;

private slots:
    void on_pushButton_clicked();

private:
    Ui::GuestsInfo *ui;
    bool isMouseDown = false;
};

#endif // GUESTSINFO_H
