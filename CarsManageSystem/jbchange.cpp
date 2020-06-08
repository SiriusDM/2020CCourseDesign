#include "jbchange.h"
#include "ui_jbchange.h"

jbchange::jbchange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jbchange)
{
    ui->setupUi(this);
}

jbchange::~jbchange()
{
    delete ui;
}

void jbchange::on_pushButton_2_clicked()
{
    this->hide();
    emit changesys();
}

void jbchange::receive()
{
    this->show();
}
