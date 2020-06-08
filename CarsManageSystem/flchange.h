#ifndef FLCHANGE_H
#define FLCHANGE_H

#include <QMainWindow>

namespace Ui {
class flchange;
}

class flchange : public QMainWindow
{
    Q_OBJECT

public:
    explicit flchange(QWidget *parent = 0);
    ~flchange();

private slots:
    void on_pushButton_2_clicked();
    void receive();

signals:
    void changesys();

private:
    Ui::flchange *ui;
};

#endif // FLCHANGE_H
