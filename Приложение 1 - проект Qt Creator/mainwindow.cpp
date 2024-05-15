#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "techused.h"
#include "guestsinfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    /**/ui->setupUi(this);

    ui->gstDOB->setCalendarPopup(true);
    ui->updateGstDOB->setCalendarPopup(true);

    /***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ*********************************************************************************************************************************/
    ui->bookingDate->setCalendarPopup(true);
    ui->bookingDate_2->setCalendarPopup(true);

    ui->timeSlider->setMinimum(0); // 0 часов
    ui->timeSlider->setMaximum(13); // 13 часов (22:00 - 9:00 = 12 часов)
    ui->timeSlider->setSingleStep(1); // Шаг изменения - 1 час
    /***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ КОНЕЦ*********************************************************************************************************************************/

    // Устанавливаем дату в виджете bookingDate на сегодняшний день
    ui->bookingDate->setMinimumDate(QDate::currentDate());
    ui->bookingDate->setDate(QDate::currentDate());

    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("alternate-background-color:#ddd1ff; background-color:#e9ebf4;selection-background-color:#5863c1; selection-color:white; border-bottom-right-radius: 16px;border-bottom-left-radius: 16px;");

    ui->updateTableView->setAlternatingRowColors(true);
    ui->updateTableView->setStyleSheet("alternate-background-color: #ddd1ff; background-color:#e9ebf4; selection-background-color:#5863c1; selection-color:white; border-bottom-right-radius: 16px;");

    ui->deleteTableView->setAlternatingRowColors(true);
    ui->deleteTableView->setStyleSheet("alternate-background-color: #ddd1ff; background-color:#e9ebf4; selection-background-color:#5863c1; selection-color:white; border-bottom-right-radius: 16px;border-bottom-left-radius: 16px;");

    /***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ*********************************************************************************************************************************/
    ui->bookingTableView->setAlternatingRowColors(true);
    ui->bookingTableView->setStyleSheet("alternate-background-color: #ddd1ff; background-color:#e9ebf4; selection-background-color:#5863c1; selection-color:white; border-bottom-right-radius: 16px;");

    ui->bookingTableView_2->setAlternatingRowColors(true);
    ui->bookingTableView_2->setStyleSheet("alternate-background-color: #ddd1ff; background-color:#e9ebf4; selection-background-color:#5863c1; selection-color:white;");

    if(!dbUtils.connectToDB("uhzczdvq"))
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка открытия базы данных.");
    }
    /***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ КОНЕЦ*********************************************************************************************************************************/

    loadTotalData();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 51);
    ui->tableView->setColumnWidth(1, 180);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 190);

    /***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ*********************************************************************************************************************************/

    connect(ui->PC_1, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_2, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_3, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_4, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_5, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_6, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_7, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_8, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_9, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_10, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_11, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_12, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_13, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_14, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_15, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_16, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_17, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_18, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_19, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_20, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_21, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_22, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_23, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_24, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_25, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_26, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_27, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_28, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_29, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);
    connect(ui->PC_30, &QPushButton::clicked, this, &MainWindow::on_PC_defaultClicked);

    connect(ui->timeSlider, &QSlider::valueChanged, this, &MainWindow::updateTimeLabel);

    connect(ui->timeEdit, &QTimeEdit::timeChanged, this, &MainWindow::on_timeEdit_timeChanged);
    connect(ui->timeEdit_2, &QTimeEdit::timeChanged, this, &MainWindow::on_timeEdit_timeChanged);
    /***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ КОНЕЦ*********************************************************************************************************************************/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTotalData()
{
    int lastID = dbUtils.getTotalGst().toInt();

    QString lastIDString = QString::number(lastID);

    if(lastIDString.length() == 1)
    {
        lastIDString = "00" + lastIDString;
    }
    else if(lastIDString.length() == 2)
    {
        lastIDString = "0" + lastIDString;
    }

    ui->gstLabel->setText(lastIDString);
    ui->gstLabel_2->setText(lastIDString);
    ui->gstLabel_3->setText(lastIDString);
    dbUtils.setGstDetailsB(ui->tableView);
}

/***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ*********************************************************************************************************************************/

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isMouseDown = true;
        mousePoint = event->globalPos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isMouseDown = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint delta = event->globalPos() - mousePoint;
    if(isMouseDown == true)
        move(x() + delta.x(), y() + delta.y());
    else
        move(x()+delta.x(), y()+delta.y());
        mousePoint = event->globalPos();
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::on_minimizeButton_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}
/***************************************************************************************************СИСТЕМА БРОНИРОВАНИЯ КОНЕЦ*********************************************************************************************************************************/

void MainWindow::on_pushButton_clicked()
{
    ui->searchTextBox->setText("");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 51);
    ui->tableView->setColumnWidth(1, 180);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 190);
}

void MainWindow::on_searchButton_clicked()
{
    loadTotalData();
    selectedPushButton(ui->searchButton);
    deselectedPushButton(ui->deleteGstButton);
    deselectedPushButton(ui->techButton);
    deselectedPushButton(ui->aboutButton);
    deselectedPushButton(ui->updateGstButton);
    deselectedPushButton(ui->addGstButton);
    deselectedPushButton(ui->bookingButton);

    dbUtils.setGstDetailsB(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 51);
    ui->tableView->setColumnWidth(1, 180);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 190);

    ui->searchStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addGstButton_clicked()
{
    selectedPushButton(ui->addGstButton);
    deselectedPushButton(ui->deleteGstButton);
    deselectedPushButton(ui->techButton);
    deselectedPushButton(ui->aboutButton);
    deselectedPushButton(ui->updateGstButton);
    deselectedPushButton(ui->searchButton);
    deselectedPushButton(ui->bookingButton);

    ui->searchStackedWidget->setCurrentIndex(3);
}

void MainWindow::on_updateGstButton_clicked()
{
    selectedPushButton(ui->updateGstButton);
    deselectedPushButton(ui->deleteGstButton);
    deselectedPushButton(ui->techButton);
    deselectedPushButton(ui->aboutButton);
    deselectedPushButton(ui->searchButton);
    deselectedPushButton(ui->addGstButton);
    deselectedPushButton(ui->bookingButton);

    dbUtils.setGstDetailsS(ui->updateTableView);
    ui->updateTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->updateTableView->setColumnWidth(0, 51);
    ui->updateTableView->setColumnWidth(1, 180);
    ui->updateTableView->setColumnWidth(2, 120);
    ui->searchStackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->gstName->text().trimmed().isEmpty() ||
       ui->gstUsername->text().trimmed().isEmpty() ||
       ui->gstEmail->text().trimmed().isEmpty() ||
       ui->gstPhone->text().trimmed().isEmpty() ||
       ui->gstPassword->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Предупреждение", "Все поля должны быть заполнены!");
    }
    else
    {

        QSqlQuery* sqlQuery = new QSqlQuery(dbUtils.db);
        QString formattedDate = QDate::fromString(ui->gstDOB->text().trimmed(), "dd.MM.yyyy").toString("yyyy-MM-dd");

        if(dbUtils.db.isOpen())
        {
            sqlQuery->prepare("insert into guests (full_name, username, date_of_birth, phone_number, email, password) "
                             "values ('" +
                                ui->gstName->text().trimmed() + "' , '" +
                                ui->gstUsername->text().trimmed() + "' , '" +
                                formattedDate + "' , '" +
                                ui->gstPhone->text().trimmed() + "' , '" +
                                ui->gstEmail->text().trimmed() + "' , '" +
                                ui->gstPassword->text().trimmed() + "');"
                             );
            if(sqlQuery->exec())
            {
                QMessageBox::information(this, "Успешно", "Пользователь добавлен.");
            }
            else
            {
                QMessageBox::critical(this, "Ошибка", "" + sqlQuery->lastError().text());
                qDebug() << "Error : "<<sqlQuery->lastError().text() << sqlQuery->isValid();
            }
        }
    }
}

void MainWindow::on_deleteGstButton_clicked()
{
    loadTotalData();
    selectedPushButton(ui->deleteGstButton);
    deselectedPushButton(ui->updateGstButton);
    deselectedPushButton(ui->techButton);
    deselectedPushButton(ui->aboutButton);
    deselectedPushButton(ui->searchButton);
    deselectedPushButton(ui->addGstButton);
    deselectedPushButton(ui->bookingButton);

    dbUtils.setGstDetailsB(ui->deleteTableView);
    ui->deleteTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->deleteTableView->setColumnWidth(0, 51);
    ui->deleteTableView->setColumnWidth(1, 180);
    ui->deleteTableView->setColumnWidth(2, 120);
    ui->deleteTableView->setColumnWidth(3, 100);
    ui->deleteTableView->setColumnWidth(4, 100);
    ui->deleteTableView->setColumnWidth(5, 190);
    ui->searchStackedWidget->setCurrentIndex(5);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString id = ui->tableView->model()->index(index.row(), 0).data().toString();

    GuestsInfo* gst = new GuestsInfo(this, id);
    gst->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    gst->setAttribute(Qt::WA_TranslucentBackground);
    gst->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->updateGstName->text().trimmed().isEmpty() || ui->updateGstPassword->text().trimmed().isEmpty() ||
            ui->updateGstEmail->text().trimmed().isEmpty() || ui->updateGstPhone->text().trimmed().isEmpty() ||
            ui->updateGstUsername->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Предупреждение", "Все поля должны быть заполнены!");
    }
    else
    {
        QSqlQuery* sqlQuery = new QSqlQuery(dbUtils.db);
        if(dbUtils.db.isOpen())
        {
            sqlQuery->prepare("UPDATE guests SET "
                              "full_name='" + ui->updateGstName->text().trimmed() + "'," +
                              "username='" + ui->updateGstUsername->text().trimmed() + "'," +
                              "email='" + ui->updateGstEmail->text().trimmed() + "'," +
                              "phone_number='" + ui->updateGstPhone->text().trimmed() + "'," +
                              "password='" + ui->updateGstPassword->text().trimmed() + "'," +
                              "date_of_birth=to_date('" + ui->updateGstDOB->date().toString("yyyy-MM-dd") + "', 'YYYY-MM-DD') WHERE id='" + ui->updateGstID->text()+"';");
            if(sqlQuery->exec())
            {
                QMessageBox::information(this, "Успешно", "Данные пользователя успешно обновлены!");
                dbUtils.setGstDetailsS(ui->updateTableView);
            }
            else
            {
                QMessageBox::critical(this, "Ошибка", "" + sqlQuery->lastError().text());
                qDebug() << "Error : "<<sqlQuery->lastError().text() << sqlQuery->isValid();
            }
        }
    }
}

void MainWindow::on_updateTableView_doubleClicked(const QModelIndex &index)
{
     QString id = ui->updateTableView->model()->index(index.row(), 0).data().toString();
     ui->updateGstID->setText(id);

     QSqlQuery* qry = dbUtils.showGstDetailsToLineEdit(id);

     QString dateOfBirth = qry->value("date_of_birth").toString();
     QDate date = QDate::fromString(dateOfBirth, "yyyy-MM-dd");

     ui->updateGstName->setText(qry->value("full_name").toString());
     ui->updateGstUsername->setText(qry->value("username").toString());
     ui->updateGstEmail->setText(qry->value("email").toString());
     ui->updateGstDOB->setDate(date);
     ui->updateGstPassword->setText(qry->value("password").toString());
     ui->updateGstPhone->setText(qry->value("phone_number").toString());
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->updateGstName->setText("");
    ui->updateGstUsername->setText("");
    ui->updateGstEmail->setText("");
    ui->updateGstPassword->setText("");
    ui->updateGstPhone->setText("");
}

void MainWindow::on_deleteTableView_doubleClicked(const QModelIndex &index)
{
    QString id = ui->deleteTableView->model()->index(index.row(), 0).data().toString();

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить пользователя с ID '" + id + "?");

    if(reply == QMessageBox::Yes)
    {
        dbUtils.deleteGstRecord(id);
    }
}

/*void MainWindow::on_deleteTableView_clicked(const QModelIndex &index)
{
    int selectedRow = index.row();
    ui->tableView->selectRow(selectedRow);
}*/

void MainWindow::on_deleteUserButton_clicked() {

    QModelIndexList selectedList = ui->deleteTableView->selectionModel()->selectedRows();
    if (!selectedList.isEmpty())
    {
        QModelIndex selected = selectedList.first();

        QString id = selected.sibling(selected.row(), 0).data().toString();

        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить пользователя с ID '" + id + "?");
        if(reply == QMessageBox::Yes)
        {
            dbUtils.deleteGstRecord(id);
        }
    }
    else
    {
        QMessageBox::critical(this, "Предупреждение", "Удаление невозможно!\nПожалуйста, выберите пользователя, которого хотите удалить.");
    }
}

void MainWindow::on_searchTextBox_returnPressed()
{
    ui->tableView->setModel(NULL);
    dbUtils.searchGstDetails(ui->tableView, ui->searchTextBox->text().trimmed());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 51);
    ui->tableView->setColumnWidth(1, 180);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 190);
}

void MainWindow::selectedPushButton(QPushButton *button)
{
    button->setStyleSheet("QPushButton{text-align:left; padding-left:20px; border:none; border-left:6px solid #6f489d; color:rgb(233, 235, 244); background:#333333;} QPushButton:hover{text-align:left; border:none; color:rgb(233, 235, 244); border-left:6px solid #6f489d; background:#333;}");
}

void MainWindow::deselectedPushButton(QPushButton *button)
{
    button->setStyleSheet("QPushButton{text-align:left; padding-left:26px; border:none; color:rgb(233, 235, 244); background:#1F1F1F;} QPushButton:hover{text-align:left; padding-left:30px; border:none; color:rgb(233, 235, 244); background:#333;}");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->gstName->setText("");
    ui->gstPassword->setText("");
    ui->gstEmail->setText("");
    ui->gstUsername->setText("");
    ui->gstPhone->setText("");
}

void MainWindow::on_techButton_clicked()
{
    TechUsed* tech = new TechUsed(this);

    tech->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    tech->setAttribute(Qt::WA_TranslucentBackground);
    tech->show();
}

void MainWindow::on_aboutButton_clicked()
{
    About* abt = new About(this);
    abt->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    abt->setWindowModality(Qt::ApplicationModal);
    abt->setAttribute(Qt::WA_TranslucentBackground);
    abt->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    loadTotalData();
    dbUtils.setGstDetailsB(ui->deleteTableView);
}

void MainWindow::on_searchTextBox_2_returnPressed()
{
    ui->tableView->setModel(NULL);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 51);
    ui->tableView->setColumnWidth(1, 180);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 190);
    dbUtils.searchGstDetails(ui->deleteTableView, ui->searchTextBox_2->text().trimmed());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->searchTextBox_2->setText("");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 51);
    ui->tableView->setColumnWidth(1, 180);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 190);
}

/********************************************************************************СИСТЕМА БРОНИРОВАНИЯ**********************************************************************************************************************/

void MainWindow::on_bookingButton_clicked()
{
    selectedPushButton(ui->bookingButton);
    deselectedPushButton(ui->updateGstButton);
    deselectedPushButton(ui->deleteGstButton);
    deselectedPushButton(ui->techButton);
    deselectedPushButton(ui->aboutButton);
    deselectedPushButton(ui->searchButton);
    deselectedPushButton(ui->addGstButton);

    ui->searchStackedWidget->setCurrentIndex(1);
}

void MainWindow::updateTimeLabel(int value)
{
    // Преобразуем значение ползунка в часы
    int hours = value + 9; // Добавляем 10 часов (начальное значение)

    // Обновляем currentTime с полученным временем
    currentTime = QTime(hours, 0);

    // Обновляем метку времени с новым значением
    ui->timeLabel->setText(currentTime.toString("hh:mm"));

    // Получаем дату бронирования из виджета bookingDate
    QDate bookingDate = ui->bookingDate->date();

    // Формируем строковое представление даты для SQL запроса
    QString bookingDateString = bookingDate.toString("yyyy-MM-dd");

    // Подготовка SQL запроса
    QSqlQuery query;
    query.prepare("SELECT seat_id FROM public.booking "
                  "WHERE seat_id BETWEEN 1 AND 30 "
                  "AND booking_date = :bookingDate "
                  "AND start_time <= :currentTime "
                  "AND end_time > :currentTime");
    query.bindValue(":bookingDate", bookingDateString);
    query.bindValue(":currentTime", currentTime.toString("hh:mm"));

    // Выполнение запроса
    if(query.exec())
    {
        // Получаем список забронированных мест
        QList<int> bookedSeats;
        while(query.next())
        {
            int seatId = query.value(0).toInt();
            bookedSeats.append(seatId);
        }

        // Деактивируем/активируем кнопки
        for(int i = 1; i <= 30; ++i)
        {
            QString buttonName = "PC_" + QString::number(i);
            QPushButton* button = findChild<QPushButton*>(buttonName);
            if(button)
            {
                if(bookedSeats.contains(i))
                    button->setEnabled(false);
                else
                    button->setEnabled(true);
            }
        }
    }
    else
    {
        qDebug() << "Error executing SQL query:" << query.lastError().text();
    }
}

void MainWindow::on_PC_seatClicked()
{
    // Загрузка данных и установка таблицы
    loadTotalData();
    dbUtils.setGstDetailsS(ui->bookingTableView);
    ui->bookingTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->bookingTableView->setColumnWidth(0, 60);
    ui->bookingTableView->setColumnWidth(1, 220);
    ui->bookingTableView->setColumnWidth(2, 140);

    // Получение информации о месте
    QPair<int, QPair<QString, QString>> seatInfo = dbUtils.getSeatInfo(seatId);
    ui->zone->setText(seatInfo.second.second);
    ui->seat->setText(seatInfo.second.first);

    // Установка значения currentTime в timeEdit
    ui->timeEdit->setMinimumTime(currentTime);
    ui->timeEdit->setTime(currentTime);

    // Установка значений и ограничений для timeEdit_2
    QTime minTime = currentTime.addSecs(3600); // currentTime + 1 час
    ui->timeEdit_2->setMinimumTime(minTime);
    ui->timeEdit_2->setTime(minTime);

    QDate date = ui->bookingDate->date();
    ui->bookingDate_2->setDate(date);
    ui->bookingDate_2->setMinimumDate(date);

    // Переключение на нужный стек
    ui->searchStackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PC_defaultClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(button){
        QString buttonName = button->objectName();
        seatId = buttonName.mid(3).toInt(); // Получаем id места из имени кнопки
        on_PC_seatClicked();
    }
}

void MainWindow::on_timeEdit_timeChanged(const QTime &time)
{
    QTime timeEditTime = ui->timeEdit->time();
    QTime timeEdit2Time = ui->timeEdit_2->time();
    QTime newTime = QTime(time.hour(), 0);

    // Проверяем, изменились ли минуты
    if (time.minute() != 0) {
        // Если минуты изменились, устанавливаем их в 0
        if (sender() == ui->timeEdit) {
            ui->timeEdit->setTime(newTime);
        } else if (sender() == ui->timeEdit_2) {
            ui->timeEdit_2->setTime(newTime);
        }
    }

    // Проверяем, если время в timeEdit_2 меньше или равно времени в timeEdit
    if (timeEdit2Time <= timeEditTime) {
        // Устанавливаем время в timeEdit_2 на 1 час больше времени в timeEdit
        newTime = timeEditTime.addSecs(3600);
        ui->timeEdit_2->setTime(newTime);
    }

    // Проверяем, активировать или деактивировать кнопки в зависимости от времени
    if (timeEditTime > QTime(20, 0)) {
        ui->timeButton_3->setDisabled(true);
        ui->timeButton_3->setStyleSheet("QPushButton { background-color: #CCCCCC; color: #666666; border: 1px solid #999999; border-radius:5px; }");
    } else {
        ui->timeButton_3->setEnabled(true);
        ui->timeButton_3->setStyleSheet("QPushButton { background:#6f489d; border:none; color:white; border-radius:5px; } QPushButton:hover { background-color: #2e2e2e; border:2px solid #6f489d; color:#6f489d; border-radius:5px; }");
    }

    if (timeEditTime > QTime(17, 0)) {
        ui->timeButton_6->setDisabled(true);
        ui->timeButton_6->setStyleSheet("QPushButton { background-color: #CCCCCC; color: #666666; border: 1px solid #999999; border-radius:5px; }");
    } else {
        ui->timeButton_6->setEnabled(true);
        ui->timeButton_6->setStyleSheet("QPushButton { background:#6f489d; border:none; color:white; border-radius:5px; } QPushButton:hover { background-color: #2e2e2e; border:2px solid #6f489d; color:#6f489d; border-radius:5px; }");
    }

    if (timeEditTime > QTime(11, 0)) {
        ui->timeButton_12->setDisabled(true);
        ui->timeButton_12->setStyleSheet("QPushButton { background-color: #CCCCCC; color: #666666; border: 1px solid #999999; border-radius:5px; }");
    } else {
        ui->timeButton_12->setEnabled(true);
        ui->timeButton_12->setStyleSheet("QPushButton { background:#6f489d; border:none; color:white; border-radius:5px; } QPushButton:hover { background-color: #2e2e2e; border:2px solid #6f489d; color:#6f489d; border-radius:5px; }");
    }
}

void MainWindow::on_cancelButton_clicked()
{
    ui->searchStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_timeButton_1_clicked()
{
    QTime timeEditTime = ui->timeEdit->time();
    ui->timeEdit_2->setTime(timeEditTime.addSecs(3600));
}


void MainWindow::on_timeButton_3_clicked()
{
    QTime timeEditTime = ui->timeEdit->time();
    ui->timeEdit_2->setTime(timeEditTime.addSecs(10800));
}


void MainWindow::on_timeButton_6_clicked()
{
    QTime timeEditTime = ui->timeEdit->time();
    ui->timeEdit_2->setTime(timeEditTime.addSecs(21600));
}


void MainWindow::on_timeButton_12_clicked()
{
    QTime timeEditTime = ui->timeEdit->time();
    ui->timeEdit_2->setTime(timeEditTime.addSecs(43200));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->searchTextBox_3->setText("");
    loadTotalData();
    dbUtils.setGstDetailsS(ui->bookingTableView);
    ui->bookingTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->bookingTableView->setColumnWidth(0, 60);
    ui->bookingTableView->setColumnWidth(1, 220);
    ui->bookingTableView->setColumnWidth(2, 140);
}


void MainWindow::on_searchTextBox_3_textChanged(const QString &arg1)
{
    ui->bookingTableView->setModel(NULL);
    dbUtils.searchGstDetails(ui->bookingTableView, arg1);
    ui->bookingTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->bookingTableView->setColumnWidth(0, 60);
    ui->bookingTableView->setColumnWidth(1, 220);
    ui->bookingTableView->setColumnWidth(2, 140);
}

void MainWindow::on_bookingButton_2_clicked()
{
    if(ui->bookingDate_2->text().trimmed().isEmpty() ||
        ui->timeEdit->text().trimmed().isEmpty() ||
        ui->timeEdit_2->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Предупреждение", "Все поля должны быть заполнены!");
    } else {
        QModelIndexList selectedList = ui->bookingTableView->selectionModel()->selectedRows();
        if (!selectedList.isEmpty()) {
            QModelIndex selected = selectedList.first();
            QString currentUserId = selected.sibling(selected.row(), 0).data().toString();
            // Получаем информацию о пользователе
            QPair<QString, QPair<QString, QString>> userData = dbUtils.getData(currentUserId);
            QString fullName = userData.first;
            QString email = userData.second.first;
            QString phoneNumber = userData.second.second;

            QSqlQuery* sqlQuery = new QSqlQuery(dbUtils.db);
            QString formattedDate = QDate::fromString(ui->bookingDate_2->text().trimmed(), "dd.MM.yyyy").toString("yyyy-MM-dd");
            QString startTimeStr = ui->timeEdit->time().toString("HH:mm");
            QString endTimeStr = ui->timeEdit_2->time().toString("HH:mm");

            // Проверяем забронировано ли место
            sqlQuery->prepare("SELECT booking_id FROM public.booking "
                              "WHERE seat_id = :seatId "
                              "AND booking_date = :formattedDate "
                              "AND ((start_time <= :startTimeStr AND :startTimeStr < end_time) "
                              "OR (start_time < :endTimeStr AND :endTimeStr <= end_time)"
                              "OR (:startTimeStr <= start_time And end_time <= :endTimeStr))");
            sqlQuery->bindValue(":seatId", seatId);
            sqlQuery->bindValue(":formattedDate", formattedDate);
            sqlQuery->bindValue(":startTimeStr", startTimeStr);
            sqlQuery->bindValue(":endTimeStr", endTimeStr);
            if (sqlQuery->exec() && sqlQuery->next()) {
                // Место забронировано
                int bookingId = sqlQuery->value(0).toInt();
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Предупреждение", "Место с id " + QString::number(seatId) + " уже забронировано (booking_id: " + QString::number(bookingId) + "). Вы хотите удалить бронь?",
                                              QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    // Выполняем удаление брони
                    sqlQuery->prepare("DELETE FROM public.booking WHERE booking_id = :bookingId");
                    sqlQuery->bindValue(":bookingId", bookingId);
                    if (sqlQuery->exec()) {
                        QMessageBox::information(this, "Успешное удаление", "Бронь успешно удалена!");
                    } else {
                        QMessageBox::critical(this, "Ошибка удаления", "Произошла ошибка при удалении брони.");
                    }
                }
                return; // Прерываем процесс бронирования
            }

            // Формируем сообщение для отображения в QMessageBox
            QString message = QString("Место: %1\nЗона: %2\n\nПользователь:\nФИО: %3\nEmail: %4\nНомер телефона: %5\nДата: %6\nС: %7 По: %8")
                                  .arg(ui->seat->text().trimmed())
                                  .arg(ui->zone->text().trimmed())
                                  .arg(fullName)
                                  .arg(email)
                                  .arg(phoneNumber)
                                  .arg(formattedDate)
                                  .arg(startTimeStr)
                                  .arg(endTimeStr);
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Подтверждение бронирования", message,
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                if(dbUtils.db.isOpen())
                {
                    sqlQuery->prepare("INSERT INTO public.booking (seat_id, guest_id, booking_date, start_time, end_time) "
                                      "VALUES (:seatId, :guestId, :bookingDate, :startTime, :endTime)");

                    sqlQuery->bindValue(":seatId", seatId);
                    sqlQuery->bindValue(":guestId", currentUserId);
                    sqlQuery->bindValue(":bookingDate", formattedDate);
                    sqlQuery->bindValue(":startTime", startTimeStr);
                    sqlQuery->bindValue(":endTime", endTimeStr);
                    if(sqlQuery->exec())
                    {
                        QMessageBox::information(this, "Успешное бронирование", "Бронирование выполнено успешно!");
                        ui->searchStackedWidget->setCurrentIndex(1);
                    }
                    else
                    {
                        QMessageBox::critical(this, "Ошибка", "" + sqlQuery->lastError().text());
                        qDebug() << "Error : "<<sqlQuery->lastError().text() << sqlQuery->isValid();
                    }
                }
                else {
                    QMessageBox::critical(this, "Ошибка бронирования", "Ошибка при выполнении бронирования. Пожалуйста, попробуйте еще раз.");
                }
            }
        }
        else
        {
            QMessageBox::critical(this, "Предупреждение", "Пользователь не выбран!\nПожалуйста, выберите пользователя для бронирования.");
        }
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    dbUtils.setBookingDetailsB(ui->bookingTableView_2);
    ui->bookingTableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->bookingTableView_2->setColumnWidth(0, 51);
    ui->bookingTableView_2->setColumnWidth(1, 150);
    ui->bookingTableView_2->setColumnWidth(2, 200);
    ui->bookingTableView_2->setColumnWidth(3, 120);
    ui->bookingTableView_2->setColumnWidth(4, 110);
    ui->bookingTableView_2->setColumnWidth(5, 110);
    ui->searchStackedWidget->setCurrentIndex(6);
}


void MainWindow::on_backButton_clicked()
{
    ui->searchStackedWidget->setCurrentIndex(1);
}


void MainWindow::on_deleteBokingButton_clicked()
{
    QModelIndexList selectedList = ui->bookingTableView_2->selectionModel()->selectedRows();
    if (!selectedList.isEmpty())
    {
        QModelIndex selected = selectedList.first();

        QString id = selected.sibling(selected.row(), 0).data().toString();

        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите отменить бронь с ID '" + id + "?");
        if(reply == QMessageBox::Yes)
        {
            dbUtils.deleteBookingRecord(id);
            dbUtils.setBookingDetailsB(ui->bookingTableView_2);
        }
    }
    else
    {
        QMessageBox::critical(this, "Предупреждение", "Невозможно отменить бронь!\nПожалуйста, выберите сеанс, который хотите отменить.");
    }
}

void MainWindow::on_bookingTableView_2_doubleClicked(const QModelIndex &index)
{
    QString id = ui->bookingTableView_2->model()->index(index.row(), 0).data().toString();

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите отменить бронь с ID '" + id + "?");

    if(reply == QMessageBox::Yes)
    {
        dbUtils.deleteBookingRecord(id);
        dbUtils.setBookingDetailsB(ui->bookingTableView_2);
    }
}


void MainWindow::on_searchTextBox_4_textChanged(const QString &arg1)
{
    ui->bookingTableView_2->setModel(NULL);
    dbUtils.searchBookingDetails(ui->bookingTableView_2, arg1);
    ui->bookingTableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->bookingTableView_2->setColumnWidth(0, 51);
    ui->bookingTableView_2->setColumnWidth(1, 150);
    ui->bookingTableView_2->setColumnWidth(2, 200);
    ui->bookingTableView_2->setColumnWidth(3, 120);
    ui->bookingTableView_2->setColumnWidth(4, 110);
    ui->bookingTableView_2->setColumnWidth(5, 110);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->searchTextBox_4->setText("");
    ui->bookingTableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->bookingTableView_2->setColumnWidth(0, 51);
    ui->bookingTableView_2->setColumnWidth(1, 150);
    ui->bookingTableView_2->setColumnWidth(2, 200);
    ui->bookingTableView_2->setColumnWidth(3, 120);
    ui->bookingTableView_2->setColumnWidth(4, 110);
    ui->bookingTableView_2->setColumnWidth(5, 110);
}

