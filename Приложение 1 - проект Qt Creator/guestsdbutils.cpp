#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>

class GuestsDatabaseUtils
{
    public:

    QSqlDatabase guestsDB;

    bool connectToDB(QString dbName)
    {
        guestsDB = QSqlDatabase::addDatabase("QPSQL");
        guestsDB.setPort(5432);
        guestsDB.setDatabaseName(dbName);
        guestsDB.setHostName("balarama.db.elephantsql.com");
        guestsDB.setUserName("uhzczdvq");
        guestsDB.setPassword("mzpPP5wIvFp2mFAljI-VFle55Vcqapwk");

        if(guestsDB.open())
        {
            qDebug() << ("Подключение к базе данных выполнено успешно!");
            return true;
        }
        else
        {
            qDebug() << ("Ошибка подключения к базе данных");
            return false;
        }
    }

    void closeDBConnection()
    {

        if(guestsDB.isValid())
        {
            guestsDB.close();
            guestsDB.removeDatabase(QSqlDatabase::defaultConnection);
        }
    }

    QSqlQuery* getData(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(guestsDB);

        qry->prepare("SELECT * FROM guests WHERE id='" + id + "';");

        if(qry->exec())
        {
            qry->next();
            return qry;

           // label->setText(qry->value(1).toString());
            qDebug() << "Информация о пользователях получена из базы данных";
        }
        else
        {
            return NULL;
            qDebug() << "Failed";
        }
    }
};
