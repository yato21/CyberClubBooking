#include "guestsinfo.h"
#include "ui_guestsinfo.h"


GuestsInfo::GuestsInfo(QWidget *parent, QString id) :
    QWidget(parent),
    ui(new Ui::GuestsInfo)
{
    ui->setupUi(this);

    ui->label_7->setText("<html><head/><body><p align='center'>" + id + "</p></body></html>");

    QSqlQuery* info = new QSqlQuery();
    info = gstDBUtils.getData(id);

    // Personal Info
    ui->showGstName->setText(info->value(1).toString());   //фио
    ui->showGstUsername->setText(info->value(2).toString());    //логин
    ui->showGstPassword->setText(info->value(3).toString()); //пароль
    ui->showGstEmail->setText(info->value(4).toString());  //майл
    ui->showGstPhone->setText(info->value(5).toString());  //номер
    ui->showGstDOB->setText(info->value(6).toString());//др
}

GuestsInfo::~GuestsInfo()
{
    delete ui;
}

void GuestsInfo::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isMouseDown = true;
        mousePoint = event->globalPos();
    }
}

void GuestsInfo::mouseReleaseEvent(QMouseEvent *event)
{
    isMouseDown = false;
}

void GuestsInfo::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint delta = event->globalPos() - mousePoint;
    if(isMouseDown == true)
        move(x() + delta.x(), y() + delta.y());
    else
        move(x()+delta.x(), y()+delta.y());
        mousePoint = event->globalPos();
}

void GuestsInfo::on_pushButton_clicked()
{
    this->close();
}
