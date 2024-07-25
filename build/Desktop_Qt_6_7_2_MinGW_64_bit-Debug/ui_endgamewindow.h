/********************************************************************************
** Form generated from reading UI file 'endgamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAMEWINDOW_H
#define UI_ENDGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Endgamewindow
{
public:
    QPushButton *restart_button;
    QPushButton *exit_button;
    QLabel *game_result;

    void setupUi(QDialog *Endgamewindow)
    {
        if (Endgamewindow->objectName().isEmpty())
            Endgamewindow->setObjectName("Endgamewindow");
        Endgamewindow->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/cities_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Endgamewindow->setWindowIcon(icon);
        Endgamewindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: green;\n"
"}"));
        restart_button = new QPushButton(Endgamewindow);
        restart_button->setObjectName("restart_button");
        restart_button->setGeometry(QRect(50, 240, 83, 29));
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
        exit_button = new QPushButton(Endgamewindow);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(270, 240, 83, 29));
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
        game_result = new QLabel(Endgamewindow);
        game_result->setObjectName("game_result");
        game_result->setGeometry(QRect(110, 70, 171, 61));

        retranslateUi(Endgamewindow);

        QMetaObject::connectSlotsByName(Endgamewindow);
    } // setupUi

    void retranslateUi(QDialog *Endgamewindow)
    {
        Endgamewindow->setWindowTitle(QCoreApplication::translate("Endgamewindow", "Cities", nullptr));
        restart_button->setText(QCoreApplication::translate("Endgamewindow", "Restart", nullptr));
        exit_button->setText(QCoreApplication::translate("Endgamewindow", "Exit", nullptr));
        game_result->setText(QCoreApplication::translate("Endgamewindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Endgamewindow: public Ui_Endgamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEWINDOW_H
