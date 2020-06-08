#include "ddchange.h"
#include "ui_ddchange.h"

ddchange::ddchange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ddchange)
{
    ui->setupUi(this);
}

ddchange::~ddchange()
{
    delete ui;
}

void ddchange::on_pushButton_2_clicked()
{
    this->hide();
    emit changesys();
}

void ddchange::receive()
{
    this->show();
}
