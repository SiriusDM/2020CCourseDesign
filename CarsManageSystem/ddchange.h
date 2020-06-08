#ifndef DDCHANGE_H
#define DDCHANGE_H

#include <QMainWindow>

namespace Ui {
class ddchange;
}

class ddchange : public QMainWindow
{
    Q_OBJECT

public:
    explicit ddchange(QWidget *parent = 0);
    ~ddchange();

private slots:
    void on_pushButton_2_clicked();
    void receive();

signals:
    void changesys();
private:
    Ui::ddchange *ui;
};

#endif // DDCHANGE_H
