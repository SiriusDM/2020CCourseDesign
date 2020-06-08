/********************************************************************************
** Form generated from reading UI file 'changecarsdata.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGECARSDATA_H
#define UI_CHANGECARSDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeCarsData
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *flButton;
    QPushButton *jbButton_2;
    QPushButton *ddButton_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChangeCarsData)
    {
        if (ChangeCarsData->objectName().isEmpty())
            ChangeCarsData->setObjectName(QStringLiteral("ChangeCarsData"));
        ChangeCarsData->resize(420, 301);
        QFont font;
        font.setItalic(false);
        ChangeCarsData->setFont(font);
        centralwidget = new QWidget(ChangeCarsData);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 281, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        flButton = new QPushButton(centralwidget);
        flButton->setObjectName(QStringLiteral("flButton"));
        flButton->setGeometry(QRect(260, 60, 93, 28));
        jbButton_2 = new QPushButton(centralwidget);
        jbButton_2->setObjectName(QStringLiteral("jbButton_2"));
        jbButton_2->setGeometry(QRect(260, 110, 93, 28));
        ddButton_3 = new QPushButton(centralwidget);
        ddButton_3->setObjectName(QStringLiteral("ddButton_3"));
        ddButton_3->setGeometry(QRect(260, 160, 93, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1, 59, 191, 31));
        QFont font2;
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1, 109, 201, 31));
        label_3->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1, 159, 181, 31));
        label_4->setFont(font2);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(150, 220, 93, 28));
        ChangeCarsData->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChangeCarsData);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 420, 26));
        ChangeCarsData->setMenuBar(menubar);
        statusbar = new QStatusBar(ChangeCarsData);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChangeCarsData->setStatusBar(statusbar);

        retranslateUi(ChangeCarsData);

        QMetaObject::connectSlotsByName(ChangeCarsData);
    } // setupUi

    void retranslateUi(QMainWindow *ChangeCarsData)
    {
        ChangeCarsData->setWindowTitle(QApplication::translate("ChangeCarsData", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeCarsData", "\350\275\246\350\276\206\347\247\237\350\265\201\344\277\241\346\201\257\344\277\256\346\224\271/\346\237\245\350\257\242", Q_NULLPTR));
        flButton->setText(QApplication::translate("ChangeCarsData", "\344\277\256\346\224\271/\346\237\245\350\257\242", Q_NULLPTR));
        jbButton_2->setText(QApplication::translate("ChangeCarsData", "\344\277\256\346\224\271/\346\237\245\350\257\242", Q_NULLPTR));
        ddButton_3->setText(QApplication::translate("ChangeCarsData", "\344\277\256\346\224\271/\346\237\245\350\257\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangeCarsData", "\357\203\274	\350\275\246\350\276\206\345\210\206\347\261\273\344\277\241\346\201\257", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangeCarsData", "\357\203\274	\350\275\246\350\276\206\345\237\272\346\234\254\344\277\241\346\201\257", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChangeCarsData", "\357\203\274	\347\247\237\350\275\246\350\256\242\345\215\225\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ChangeCarsData", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeCarsData: public Ui_ChangeCarsData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGECARSDATA_H
