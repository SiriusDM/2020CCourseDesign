/********************************************************************************
** Form generated from reading UI file 'flchange.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLCHANGE_H
#define UI_FLCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flchange
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *flchange)
    {
        if (flchange->objectName().isEmpty())
            flchange->setObjectName(QStringLiteral("flchange"));
        flchange->resize(727, 396);
        centralwidget = new QWidget(flchange);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 10, 281, 61));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1, 89, 331, 31));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(330, 90, 113, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 140, 113, 21));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(330, 200, 113, 21));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(330, 260, 113, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(171, 140, 161, 20));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(212, 200, 111, 20));
        label_4->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(242, 260, 71, 21));
        label_5->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 300, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(550, 300, 93, 28));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(460, 90, 256, 192));
        flchange->setCentralWidget(centralwidget);
        menubar = new QMenuBar(flchange);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 727, 26));
        flchange->setMenuBar(menubar);
        statusbar = new QStatusBar(flchange);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        flchange->setStatusBar(statusbar);

        retranslateUi(flchange);

        QMetaObject::connectSlotsByName(flchange);
    } // setupUi

    void retranslateUi(QMainWindow *flchange)
    {
        flchange->setWindowTitle(QApplication::translate("flchange", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("flchange", "\350\275\246\350\276\206\345\210\206\347\261\273\344\277\241\346\201\257\344\277\256\346\224\271/\346\237\245\350\257\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("flchange", "\345\212\237\350\203\275\351\200\211\346\213\251\357\274\2100-\344\277\256\346\224\271|1-\345\242\236\345\212\240|2-\345\210\240\351\231\244|3-\346\237\245\350\257\242\357\274\211", Q_NULLPTR));
        label_3->setText(QApplication::translate("flchange", "\350\275\246\350\276\206\347\261\273\345\236\213\347\274\226\347\240\201\357\274\2101~5\357\274\211", Q_NULLPTR));
        label_4->setText(QApplication::translate("flchange", "\350\275\246\350\276\206\347\261\273\345\236\213\345\220\215\347\247\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("flchange", "\345\272\223\345\255\230\346\225\260\351\207\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("flchange", "\346\217\220\344\272\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("flchange", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class flchange: public Ui_flchange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLCHANGE_H
