//#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QLabel>
#include <QTableView>
#include <QMessageBox>
#include <QDate>
#include <QTime>
//#include <QSqlDatabase>

class DatabaseUtils
{
    public:

    QSqlDatabase db = QSqlDatabase::database("firstConn");

    bool connectToDB(QString dbName)
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setPort(5432);
        db.setDatabaseName(dbName);
        db.setHostName("balarama.db.elephantsql.com");
        db.setUserName("uhzczdvq");
        db.setPassword("mzpPP5wIvFp2mFAljI-VFle55Vcqapwk");

        if(db.open())
        {
            qDebug() << ("Подключение к базе данных выполнено успешно!");
            return true;
        }
        else
        {
            qDebug() << ("Ошибка при подключении к базе данных");
            return false;
        }
    }

    void closeDBConnection()
    {

        if(db.isValid())
        {
            qDebug() <<"Соединение действительно";
            db.removeDatabase("firstConn");
            db.close();
        }
        else
        {
            qDebug() <<"Соединение недействительно";
        }       
    }

    QString getLastID()
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT MAX(id) FROM guests");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt() + 1;

        return QString::number(lastID);
    }

    QString getTotalGst()
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT COUNT(id) FROM guests");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt();

        return QString::number(lastID);
    }

    void setGstDetailsB(QTableView* tableView)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *querModel = new QSqlQueryModel();
            querModel->setQuery("SELECT id, full_name, username, date_of_birth, phone_number, email FROM guests ORDER BY full_name;");
            tableView->setModel(querModel);
        }
    }

    void searchGstDetails(QTableView* tableView, QString searchText)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *querModel = new QSqlQueryModel();
            QString query = "SELECT id, full_name, username, date_of_birth, phone_number, email FROM guests WHERE LOWER(full_name) LIKE LOWER('%" + searchText + "%') OR LOWER(username) LIKE LOWER('%" + searchText + "%') ORDER BY full_name;";
            querModel->setQuery(query);
            tableView->setModel(querModel);
        }
    }


    void setGstDetailsS(QTableView* tableView)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *querModel = new QSqlQueryModel();
            querModel->setQuery("SELECT id, full_name, phone_number FROM guests ORDER BY full_name;");
            tableView->setModel(querModel);
        }
    }

    QSqlQuery* showGstDetailsToLineEdit(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT * FROM guests WHERE id='" + id + "';");
        qry->exec();
        qry->next();  

        return qry;
    }

    void deleteGstRecord(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("DELETE  FROM guests WHERE id='" + id + "';");

        qry->exec();
    }

    /********************************************************************************СИСТЕМА БРОНИРОВАНИЯ**********************************************************************************************************************/

    QPair<int, QPair<QString, QString>> getSeatInfo(int seatId)
    {
        QPair<int, QPair<QString, QString>> seatInfo;

        // Отправляем SQL-запрос для получения информации о месте по его id
        QSqlQuery query;
        query.prepare("SELECT s.seat_id, s.number, z.name "
                      "FROM seats AS s "
                      "JOIN zones AS z ON s.zone_id = z.id "
                      "WHERE s.seat_id = :seatId");
        query.bindValue(":seatId", seatId);

        if (query.exec() && query.next()) {
            // Получаем результаты запроса и сохраняем их в пару
            seatInfo.first = query.value(0).toInt(); // id места
            seatInfo.second.first = query.value(1).toString(); // Номер места
            seatInfo.second.second = query.value(2).toString(); // Название зоны
        } else {
            // Если запрос не выполнен успешно, выводим сообщение об ошибке
            qDebug() << "Ошибка при выполнении SQL-запроса для получения информации о месте:";
        }

        return seatInfo;
    }

    QPair<QString, QPair<QString, QString>> getData(QString userId)
    {
        QPair<QString, QPair<QString, QString>> userData;

        // Отправляем SQL-запрос для получения информации о пользователе
        QSqlQuery query;
        query.prepare("SELECT full_name, email, phone_number FROM guests WHERE id = :userId");
        query.bindValue(":userId", userId);

        if (query.exec() && query.next()) {
            // Получаем результаты запроса и сохраняем их в пару
            userData.first = query.value(0).toString(); // ФИО
            userData.second.first = query.value(1).toString(); // Email
            userData.second.second = query.value(2).toString(); // Номер телефона
        } else {
            // Если запрос не выполнен успешно, выводим сообщение об ошибке
            qDebug() << "Ошибка при выполнении SQL-запроса для получения информации о пользователе:";
        }

        return userData;
    }

    void setBookingDetailsB(QTableView* tableView)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *queryModel = new QSqlQueryModel();
            QString queryString = "SELECT b.booking_id, s.number, g.full_name, b.booking_date, b.start_time, b.end_time "
                                  "FROM booking AS b "
                                  "JOIN guests AS g ON b.guest_id = g.id "
                                  "JOIN seats AS s ON b.seat_id = s.seat_id";
            queryModel->setQuery(queryString);
            tableView->setModel(queryModel);
        }
    }

    void deleteBookingRecord(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(db);
        qry->prepare("DELETE FROM booking WHERE booking_id=:id");
        qry->bindValue(":id", id);

        if (qry->exec())
        {
            QMessageBox::information(nullptr, "Успех", "Запись успешно удалена.");
        }
        else
        {
            QMessageBox::critical(nullptr, "Ошибка", "Ошибка при удалении записи.");
        }
    }

    void searchBookingDetails(QTableView* tableView, QString searchText)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *queryModel = new QSqlQueryModel();
            QString queryString = "SELECT b.booking_id, s.number, g.full_name, b.booking_date, b.start_time, b.end_time "
                                  "FROM booking AS b "
                                  "JOIN guests AS g ON b.guest_id = g.id "
                                  "JOIN seats AS s ON b.seat_id = s.seat_id "
                                  "WHERE g.full_name ILIKE '%" + searchText + "%' "
                                                 "OR s.number ILIKE '%" + searchText + "%'";
            queryModel->setQuery(queryString);
            tableView->setModel(queryModel);
        }
    }
};
