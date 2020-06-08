#ifndef CHANGECARSDATA_H
#define CHANGECARSDATA_H

#include <QMainWindow>

namespace Ui {
class ChangeCarsData;
}

class ChangeCarsData : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeCarsData(QWidget *parent = 0);
    ~ChangeCarsData();

private slots:
    void on_pushButton_4_clicked();
    void on_flButton_clicked();
    void receive();

    void on_jbButton_2_clicked();

    void on_ddButton_3_clicked();

signals:
    void mainsys();
    void flchangesys();
    void jbchangesys();
    void ddchangesys();

private:
    Ui::ChangeCarsData *ui;
};

#endif // CHANGECARSDATA_H
