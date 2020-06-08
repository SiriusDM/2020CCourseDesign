#ifndef JBCHANGE_H
#define JBCHANGE_H

#include <QMainWindow>

namespace Ui {
class jbchange;
}

class jbchange : public QMainWindow
{
    Q_OBJECT

public:
    explicit jbchange(QWidget *parent = 0);
    ~jbchange();

private slots:
    void on_pushButton_2_clicked();
    void receive();

signals:
    void changesys();

private:
    Ui::jbchange *ui;
};

#endif // JBCHANGE_H
