/********************************************************************************
** Form generated from reading UI file 'winnerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINNERWINDOW_H
#define UI_WINNERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Winnerwindow
{
public:
    QPushButton *restart_button;
    QPushButton *exit_button;
    QLabel *label;

    void setupUi(QDialog *Winnerwindow)
    {
        if (Winnerwindow->objectName().isEmpty())
            Winnerwindow->setObjectName("Winnerwindow");
        Winnerwindow->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/cities_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Winnerwindow->setWindowIcon(icon);
        Winnerwindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: green;\n"
"}"));
        restart_button = new QPushButton(Winnerwindow);
        restart_button->setObjectName("restart_button");
        restart_button->setGeometry(QRect(50, 250, 83, 29));
        restart_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 85, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:  rgb(0, 102, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(0, 124, 0);\n"
"}"));
        exit_button = new QPushButton(Winnerwindow);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(260, 250, 83, 29));
        exit_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 85, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:  rgb(0, 102, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(0, 124, 0);\n"
"}"));
        label = new QLabel(Winnerwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 70, 171, 61));

        retranslateUi(Winnerwindow);

        QMetaObject::connectSlotsByName(Winnerwindow);
    } // setupUi

    void retranslateUi(QDialog *Winnerwindow)
    {
        Winnerwindow->setWindowTitle(QCoreApplication::translate("Winnerwindow", "Cities", nullptr));
        restart_button->setText(QCoreApplication::translate("Winnerwindow", "Restart", nullptr));
        exit_button->setText(QCoreApplication::translate("Winnerwindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("Winnerwindow", "<html><head/><body><p>Wow you won! Congrats!!!</p><p>Do you want to restart?</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Winnerwindow: public Ui_Winnerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINNERWINDOW_H
