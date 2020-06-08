#include "changecarsdata.h"
#include "ui_changecarsdata.h"

ChangeCarsData::ChangeCarsData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeCarsData)
{
    ui->setupUi(this);
}

ChangeCarsData::~ChangeCarsData()
{
    delete ui;
}

void ChangeCarsData::on_pushButton_4_clicked()
{
    this->hide();
    emit mainsys();
}

void ChangeCarsData::on_flButton_clicked()
{
    this->hide();
    emit flchangesys();
}

void ChangeCarsData::receive()
{
    this->show();
}

void ChangeCarsData::on_jbButton_2_clicked()
{
    this->hide();
    emit jbchangesys();
}

void ChangeCarsData::on_ddButton_3_clicked()
{
    this->hide();
    emit ddchangesys();
}
