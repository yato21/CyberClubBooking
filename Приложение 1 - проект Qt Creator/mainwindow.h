#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QMainWindow>
#include "databaseutils.cpp"
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QSlider>

/*#include <QStringList>
#include <QDate>
#include <QPainterPath>
#include <QStandardItemModel>*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    DatabaseUtils dbUtils;

 protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint mousePoint;

private slots:
    void on_closeButton_clicked();

    void loadTotalData();

    void on_minimizeButton_clicked();

    void on_pushButton_clicked();

    void on_searchButton_clicked();

    void on_addGstButton_clicked();

    void on_updateGstButton_clicked();

    void on_pushButton_5_clicked();

    void on_deleteGstButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_updateTableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_deleteTableView_doubleClicked(const QModelIndex &index);

    void on_deleteUserButton_clicked();

    void on_searchTextBox_returnPressed();

    void on_pushButton_6_clicked();

    void selectedPushButton(QPushButton *button);

    void deselectedPushButton(QPushButton *button);

    void on_techButton_clicked();

    void on_aboutButton_clicked();

    void on_pushButton_3_clicked();

    //void on_deleteTableView_clicked(const QModelIndex &index);

    void on_searchTextBox_2_returnPressed();

    void on_pushButton_2_clicked();

    /********************************************************************************СИСТЕМА БРОНИРОВАНИЯ**********************************************************************************************************************/

    void on_bookingButton_clicked();

    void on_PC_seatClicked();

    void on_PC_defaultClicked();

    void on_cancelButton_clicked();

    void updateTimeLabel(int value);

    void on_timeEdit_timeChanged(const QTime &time);

    void on_timeButton_1_clicked();

    void on_timeButton_3_clicked();

    void on_timeButton_6_clicked();

    void on_timeButton_12_clicked();

    void on_pushButton_4_clicked();

    void on_searchTextBox_3_textChanged(const QString &arg1);

    void on_bookingButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_backButton_clicked();

    void on_deleteBokingButton_clicked();

    void on_bookingTableView_2_doubleClicked(const QModelIndex &index);

    void on_searchTextBox_4_textChanged(const QString &arg1);

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    bool isMouseDown = false;
    int seatId;
    QTime currentTime = QTime(10,0);
};

#endif // MAINWINDOW_H
