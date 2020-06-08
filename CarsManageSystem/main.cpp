#include "mainwindow.h"
#include "changecarsdata.h"
#include "flchange.h"
#include "jbchange.h"
#include "ddchange.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ChangeCarsData c;
    flchange fl;
    jbchange jb;
    ddchange dd;
    QObject::connect(&w,SIGNAL(changesys()),&c,SLOT(receive()));
    QObject::connect(&c,SIGNAL(mainsys()),&w,SLOT(receive()));
    QObject::connect(&c,SIGNAL(flchangesys()),&fl,SLOT(receive()));
    QObject::connect(&fl,SIGNAL(changesys()),&c,SLOT(receive()));
    QObject::connect(&c,SIGNAL(jbchangesys()),&jb,SLOT(receive()));
    QObject::connect(&jb,SIGNAL(changesys()),&c,SLOT(receive()));
    QObject::connect(&c,SIGNAL(ddchangesys()),&dd,SLOT(receive()));
    QObject::connect(&dd,SIGNAL(changesys()),&c,SLOT(receive()));
    fl.hide();
    jb.hide();
    dd.hide();
    c.hide();
    w.show();

    return a.exec();
}
