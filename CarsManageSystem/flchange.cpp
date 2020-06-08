#include "flchange.h"
#include "ui_flchange.h"

flchange::flchange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::flchange)
{
    ui->setupUi(this);
}

flchange::~flchange()
{
    delete ui;
}

void flchange::on_pushButton_2_clicked()
{
    this->hide();
    emit changesys();
}

void flchange::receive()
{
    this->show();
}
